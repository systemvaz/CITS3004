public class cypher 
{
	public static String caesar(String text, int key)
	{
		int i = 0;
		char replace;
		
		//text.toLowerCase();
		char[] ourarray = text.toCharArray();
		char[] newarray = new char[text.length()];
		
		for (char c : ourarray)
		{
			if(c != ' ')
			{
				replace = (char) ((int)c - key);
				newarray[i] = replace;
			}
			i++;
		}
		
		String result = String.copyValueOf(newarray);
		return result;
	}
	
	
	public static void main(String[] args)
	{
		String thetext = "Ihwy ojih u ncgynbyly qum u ahigy hugyx Jynyl. By qum hin u vlcabn ahigy von by ehyq nbun ihy xus by qcff vywigy nby alyunymn ahigy ypyl ehiqh. Ohzilnohunyfs, by qum zuwyx qcnb u alyun xuhayl qbyh bcm zlcyhx Viv xywcxyx nbun by qcff vy nby vymn ahigy ypyl ehiqh. Jynyl xcx hin quhn ni nolh uauchmn bcm zlcyhx Viv von by qum fyzn qcnb hi wbicwy von ni ai uauchmn bcg";
		
		for(int i = 1; i < 27; i++)
		{
			System.out.println(caesar(thetext, i));	
		}
	}
	
}
