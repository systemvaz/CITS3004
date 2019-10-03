/*
 * Created by JinH on Aug 14, 2018
 * Filter - filter metachacters from SQL query parameters
 */
 


/**
 * @author Alexander Varano della Vergiliana
 */
public class Filter 
{

    public Filter () 
    {

    }
    
    /* Here we are implementing checks for and sub-string replacement of various illegal meta-characters.
     * Preventing end of line, piggy-backing, union select and time delay based SQLi attacks.
     * @param s Input SQL statement string.
     * @return filterResult Cleaned SQL statement string with illegal meta-characters removed.
     */
    public String filterMetaChars (String s) 
    {    	
    	//Array of sub-strings to filter out...
    	String[] ourFilter = {"'", ";", "@@", ",", "-- ", " AND", " and", " OR", " or", " TRUE", " true", " FALSE", " false",
    						  " SELECT", " select", " UNION", " union", " INSERT", " insert", " CREATE", " create", " FROM", " from",
    						  " WHERE", " where", " DROP", " drop", " ALTER", " alter", " GRANT", " grant", " UPDATE", " update", " REVOKE", " revoke",
    						  " EXEC", " exec", " WAITFOR", " waitfor", " DELETE", " delete", " INTO", " into", " OUTFILE", " outfile", "LOAD_FILE", "load_file"};
    	
    	//Check input and if found replace illegal sub-strings with "" to remove them...
    	String filterResult = s;
    	for(int i = 0; i < ourFilter.length; i++)
    	{
    		int currentCheck = s.indexOf(ourFilter[i]);
    		if(currentCheck != -1)
    		{
    			//Meta-character found in input string. Get rid of it...
    			filterResult = filterResult.replace(ourFilter[i], "");
    		}
    	}
        
    	//Return cleaned result
        return filterResult;
    }
}
