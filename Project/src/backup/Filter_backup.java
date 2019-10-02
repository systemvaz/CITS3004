/*
 * Created on Apr 13, 2006
 *
 * Filter - filter metachacters from SQL query parameters
 */
 

/**
 * @author WAGNERPJ
 */
public class Filter {

	public Filter () {
		// none right now
	}
	
	public String filterMetaChars (String input) {
		String result = "";					// filtered result
		
		String[] pieces = input.split("\\p{Punct}");
	     for (int index = 0; index < pieces.length; index++)
	         result += pieces[index];		
		return result;
	}
}
