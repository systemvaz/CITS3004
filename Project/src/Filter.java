/*
 * Created by JinH on Aug 14, 2018
 * Filter - filter metachacters from SQL query parameters
 */
 


/**
 * @author JinH
 */
public class Filter 
{

    public Filter () 
    {
        // none right now
    }
    
    public String filterMetaChars (String s) 
    {
        /*
         * Here we are implementing checks for and sub-string replacement of various illegal meta-characters.
         * Preventing end of line, piggy-backing, union select and time delay based SQLi attacks.
         */
    	
    	String[] ourFilter = {"'", ";", "@@", ",", "-- ",
    						  " SELECT", " select", " UNION", " union", " INSERT", " insert", " CREATE", " create",
    						  " DROP", " drop", " ALTER", " alter", " GRANT", " grant", " UPDATE", " update", " REVOKE", " revoke",
    						  " EXEC", " exec", " WAITFOR", " waitfor", " DELETE", " delete", " INTO", " into", " OUTFILE", " outfile", " LOAD", " load"};
    	String filterResult = s;
    	
    	for(int i = 0; i < ourFilter.length; i++)
    	{
    		int currentCheck = s.indexOf(ourFilter[i]);
    		if(currentCheck != -1)
    		{
    			//Meta-character found in input string. Get rid of them....
    			filterResult = filterResult.replace(ourFilter[i], "");
    		}
    	}
        
        return filterResult;
    }
}
