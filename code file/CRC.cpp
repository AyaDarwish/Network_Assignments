

/*
// Delete spaces from the beginning of string
string trim (string s)
{
	int i = 0;
	while (s[i] == ' ')
		i++;

	return s.substr(i, s.length()-i+1);
}*/



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



