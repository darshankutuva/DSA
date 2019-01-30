bool
ValidateString(char *str)
{
	bool status = true;
	
	unsigned int len = strlen(str);
	
	for(unsigned int i = 0; i < len; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			continue;
		}
		else
		{
			status = false;
			
			break;
		}
	}
	
	return status;
}

void 
ToUpper(char *str)
{
	unsigned int len = strlen();
	
	for (unsigned int i = 0; i < len; i++)
	{
		if (str[i] >= 'a')
		{
			str[i] = (str[i] - 'a') + 'A';
		}
	}
}

bool 
IsAnagram(char *s1, char *s2)
{
	bool status = true;
	
	if(s1.length() != s2.length())
	{   
		status = false;
		
		goto Exit;
	}
	
	int n=s1.length(); 

	ToUpper(s1);
	
	ToUpper(s2);
	
	unsigned int map1[26], map2[26]; 
	
	for(int i = 0; i < 26; i++)
	{  
		map1[i] = 0;
		
		map2[i] = 0;
	}
	
	for(int i = 0; i < n; i++)
	{  
		map1[s1[i] - 'A']++;
		
		map2[s2[i] - 'A']++;
	}
	for(char i = 0;i < 26; i++)
	{  
		if(map1[i] != map2[i])
		{
			status = false;
			
			break;
		}
	}

Exit:

	return status;
}

int main()
{
	
	printf("Enter the first string: ");
	
	scanf("%s", s1);
	
	printf("Enter the second string: ");
	
	scanf("%s", s2);
	
	if (!ValidateString(s1))
	{
		printf("String1 not valid\n");
		
		goto Exit;
	}
	
	if (!ValidateString(s2))
	{
		printf("String2 not valid\n");
		
		goto Exit;
	}
	
	if (IsAnagram(s1, s2))
	{
		printf("String1 and String2 are anagram\n");
	}
	else
	{
		printf("String1 and String2 are not anagram\n");
	}
	
Exit:

	return 0;
}