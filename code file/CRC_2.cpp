
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



