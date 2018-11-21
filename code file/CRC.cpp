

/*
// Delete spaces from the beginning of string
string trim (string s)
{
	int i = 0;
	while (s[i] == ' ')
		i++;

	return s.substr(i, s.length()-i+1);
}*/


string CRC_XOR (string s1,string s2)
{
	string result;
	for (int i=1;i<s1.length();i++)
	{
		if (s1[i] == s2[i])
			result += '0';

		else
			result += '1';
	}
	return result;
}

string Generator(string message , string generator ,bool verifier = false)
{
	int orderofgenerator = generator.length()-1;
	string new_message = message;
	
	if(!verifier)
	{
		while (orderofgenerator > 0)
		{
			new_message += '0';
			orderofgenerator--;
		}
	}
	
	int i = 0;
	string remainder; // remainder to be
	while (i <= new_message.length())
	{
		if (i==0)
		{
			remainder = new_message.substr(0,generator.length());
			i+= generator.length();
		}
		
		if (remainder [0] == '1')
		{
			remainder = CRC_XOR (remainder,generator);
		}


		else 
			remainder = remainder.substr(1,remainder.length()-1);

		remainder += new_message[i];
		i++;		
	}
	return remainder;
}


bool verifier (string message , string generator)
{
	string remainder = Generator (message , generator,true);
	return (atoi(remainder.c_str()) == 0);
}


void alter (string& message , int index)
{
	if (message[index] == '0')
		message[index] = '1';

	else
		message[index] = '0';
}





