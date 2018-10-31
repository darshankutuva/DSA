bool 
IsAnagram(char *s1, char *s2)
{
	if(s1.length() != s2.length())
	{   
		return false;
	}
	
	int n=s1.length(); 
	
	map<char, int> mapBox1, mapBox2; 
	
	for(int i=0;i<26;i++)
	{  
		mapBox1[i+97]=0;
		
		mapBox2[i+97]=0;
	}
	
	for(int i=0;i<n;i++)
	{  
		mapBox1[s1[i]]++;
		
		mapBox2[s2[i]]++;
	}
	for(char i='a';i<'z';i++)
	{  
		if(mapBox1[i]!=mapBox2[i])
		{
			return false;
		}
	}
	return true;
 
}