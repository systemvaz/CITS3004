/*
 * Originally Created by WAGNRJP on Apr 13, 2006
 * Updated by JinH on Aug 14, 2018
 *
 * UsersDAO - data access object for users table in MySQL database
 *              includes methods for connecting, executing queries, processing
 *              result sets, and disconnecting
 * 
 * required MySQL database format:
 *     Table: users
 *     Fields: username varchar(20), upassword varchar(20)
 * 
 * need to create this users table under account information specified below
 * insert as many rows as desired
 */
 
import java.util.Properties;
import java.sql.*;

/**
 * @author JinH
 */
public class UsersDAO {
    private Connection conn = null;         // JDBC connection
    private ResultSet rset = null;          // result set for queries
    private int returnValue;                // return value for all other commands
    private int hasSSL = 0;
    private String currentLogin;
        
    void connect() {
        try
        {             
            Class.forName("com.mysql.cj.jdbc.Driver");
        }
        catch (ClassNotFoundException e) 
        {
                System.out.println ("Could not get class object for Driver");
        }
        try
        {
            conn = DriverManager.getConnection("jdbc:mysql://130.95.252.252:3306/users?allowMultiQueries=true&autoReconnect=true&useSSL=false","cits3004user", "cits3004SQL");
        }
        catch (SQLException e) {
           System.out.println ("Could not make connection to database");
        }
    }   // end - method connect
    
    // --- executeSQLQuery - execute an SQL query using a regular statement
    // ---                       with a dynamically generated query with
    // ---                       the query method generated and data passed at run-time
    void executeSQLQuery (FrontEnd fe) {
        // --- 3a) execute SQL query
        String sqlQuery = null;     // SQL query string
        Statement stmt = null;      // SQL statement object
        
        sqlQuery = "select * from users where " + 
            "username = " + "'" + fe.getUsername() + "'" + " and " + 
            "upassword = " + "'" + fe.getPassword() + "'";
        currentLogin = fe.getUsername();
        try {
           stmt = conn.createStatement();
           rset = stmt.executeQuery(sqlQuery);
        }
        catch (SQLException e) {
            System.out.println("Could not execute SQL statement: " + sqlQuery);
        }       
    }

    
    /* Execute an SQL query using a Prepared Statement
     * with a pre-compiled query and only the data parameters filled in at run-time.
     * @param fe Frontend object containing user supplied username and password.
     */
    void executeSQLQueryPrepared (FrontEnd fe) 
    {
        // --- 3a) execute SQL query
    	String sqlQuery = null;         // SQL query string
        PreparedStatement pStmt = null;  // Our prepared statement object
        
        currentLogin = fe.getUsername();
        
        //SQL statement with ? place-holders...
        sqlQuery = "select * from users where username = ? and upassword = ?";
        
        try 
        {
			pStmt = conn.prepareStatement(sqlQuery);
	        pStmt.setString(1, fe.getUsername());  //Populate placeholder for username
	        pStmt.setString(2, fe.getPassword());  //Populate placeholder for upassword
	        rset = pStmt.executeQuery();  		   //Execute prepared statement
		} 
        catch (SQLException e1) 
        {
        	System.out.println("Could not execute SQL prepared statement.");
		}          
    }
    
    // --- executeSQLNonQuery - execute an SQL command that is not a query
    void executeSQLNonQuery (String sqlCommand) {
        // --- 3b) execute SQL non-query command
        Statement stmt = null;      // SQL statement object
        try {
           stmt = conn.createStatement();
           returnValue = stmt.executeUpdate(sqlCommand);
        }
        catch (SQLException e) {
            System.out.println("Could not execute SQL command: " + sqlCommand);
        }
    }

    // --- processResultSet - process the result set
    String processResultSet () {
        // --- 4) process result set
        ResultSetMetaData rsmd = null;
        String resultString = "";
        boolean found = false;
        boolean tooMuch = false;
        int loopcount = 0;
        try {
            rsmd = rset.getMetaData();
            int columnCount = rsmd.getColumnCount();
            while (rset.next()) {
                loopcount += 1;
                if (loopcount > 1) tooMuch = true;
                for (int index = 1; index <= columnCount; index++) {
                    resultString += rset.getString(index) + "\t";
                    if (index == 1 && rset.getString(index).equals(currentLogin)) found = true;
                }
                resultString += "\n";
            }     // --- end - while
        }
        catch (SQLException sqle) {
            System.out.println("error in processing result set");
        }  
        if (resultString == "") resultString = "No result for your request!";
        else if (found && !tooMuch) 
        {
            resultString = "Login successful!";
            currentLogin = "";
        }
        return resultString;
    }   // end - method processResultSet
    
    
    // --- disconnect - disconnect from the database
    void disconnect () {
        // --- 5) disconnect from database
        try {
            if (conn != null) {
                conn.close();
            }
        }
        catch (SQLException sqle) {
            System.out.println ("Error in closing database connection");
        }
    }   // end - method disconnect

}       // end - class UsersDAO

