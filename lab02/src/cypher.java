public class cypher 
{
	public static String caesar_decrypt(String text, int key)
	{
		char replace;
		int toint;
		char[] ourarray = text.toCharArray();
		String newstring = "";
		
		for (char c : ourarray)
		{
			if(c != ' ')
			{
				if (Character.isUpperCase(c) && Character.isLetterOrDigit(c))
				{
					toint = (c + key - 65) % 26 + 65;
					replace = (char)toint;
					newstring += replace;
				}
				else if (Character.isLowerCase(c) && Character.isLetterOrDigit(c))
				{
					toint = (c + key - 97) % 26 + 97;
					replace = (char)toint;
					newstring += replace;
				}
				else if (!Character.isLetterOrDigit(c))
				{
					newstring += c;
				}
			}
			else
			{
				newstring += " ";
			}
		}
		return newstring;
	}
	
	public static String caesar_encrypt(String text, int key)
	{
		char replace;
		int toint = 0;
		
		char[] ourarray = text.toCharArray();
		String newstring = "";
		
		for (char c : ourarray)
		{
			if(c != ' ')
			{
				if (Character.isUpperCase(c) && Character.isLetterOrDigit(c))
				{
					toint = (c - key - 65) % 26 + 65;
					replace = (char)toint;
					newstring += replace;
				}
				else if (Character.isLowerCase(c) && Character.isLetterOrDigit(c))
				{
					toint = (c - key - 97) % 26 + 97;
					replace = (char)toint;
					newstring += replace;
				}
				else if (!Character.isLetterOrDigit(c))
				{
					newstring += c;
				}
			}
			else
			{
				newstring += " ";
			}
		}
		return newstring;
	}
	
	
	public static void main(String[] args)
	{
		String thetext = "Ihwy ojih u ncgynbyly qum u ahigy hugyx Jynyl. By qum hin u vlcabn ahigy von by ehyq nbun ihy xus by qcff vywigy nby alyunymn ahigy ypyl ehiqh. Ohzilnohunyfs, by qum zuwyx qcnb u alyun xuhayl qbyh bcm zlcyhx Viv xywcxyx nbun by qcff vy nby vymn ahigy ypyl ehiqh. Jynyl xcx hin quhn ni nolh uauchmn bcm zlcyhx Viv von by qum fyzn qcnb hi wbicwy von ni ai uauchmn bcg";
		
		for(int i = 0; i < 27; i++)
		{
			System.out.println("Key: " + i);
			String hacked = caesar_decrypt(thetext, i);
			String encrypt = caesar_encrypt("Onc", i);
			System.out.println(hacked);
			System.out.println(encrypt);
		}
	}
	
}
