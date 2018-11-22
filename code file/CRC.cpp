#include <iostream>
#include <fstream>
#include "string"
#include <stdlib.h>
#include <conio.h>
using namespace std;


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


int main ()
{
	bool correct;
	int choice , index ;
	string file_path , message , generator , command , transmitted_msg , remainder;

	cout << "Please enter the path of the input file \n";
	getline (cin , file_path);
	ifstream infile(file_path);

	while (infile.fail()) 
	{
		cout <<"Couldn't open the file!\nPlease enter the path of the input file \n";
		getline (cin , file_path);
		ifstream infile(file_path);
	}

	ofstream outfile("output.txt");
	

	// reading from file
	getline (infile,message);
	getline (infile,generator);	

	// Sequence
	cout<<"Please select which sequance you want: \n 1 - generator --> verifier \n 2 - generator --> verifier --> alter --> verifier"<<endl;
	cin>>choice;

	// Invalid input
	while (choice > 2 || choice < 1)
	{
		cout <<"Invalid input!\nPlease select which sequance you want: \n 1 - generator --> verifier \n 2 - generator --> verifier --> alter --> verifier"<<endl;
		cin>>choice;
	}

	// in case of seq 1
	remainder = Generator (message, generator);
	transmitted_msg = message + remainder;

	outfile<<"transmitted message : "<<transmitted_msg<<endl;
	cout <<"transmitted message : "<<transmitted_msg<<endl;

	correct = verifier (transmitted_msg ,generator);
	if(correct)
	{
		cout << "message is correct"<<endl;
		outfile << "message is correct"<<endl;
	}

	else
	{
		cout << "message is not correct"<<endl;
		outfile << "message is not correct"<<endl;
	}

	// in case of seq 2
	if (choice == 2)
	{
		cout<<"Enter the index of the bit you want to change "<<endl;
		cin>>index;

		// Index out of range
		while (index > transmitted_msg.length()-1)
		{
			cout<<"Index out of range!\nEnter the index of the bit you want to change "<<endl;
			cin>>index;
		}

		alter (transmitted_msg,index);
	    cout <<"altered message : "<<transmitted_msg<<endl;
		outfile <<"altered message : "<<transmitted_msg<<endl;
		correct = verifier (transmitted_msg ,generator);
		if(correct)
		{
			cout << "message is correct"<<endl;
			outfile << "message is correct"<<endl;
	    }
	    else
	    {
			cout << "message is not correct"<<endl;
			outfile << "message is not correct"<<endl;
	    }

	}

	/*
	// Parsing Commands --> this code works if you wanna enter the following commands in cmd
	// 1- generator <file | verifier 
	// 2- generator <file | verifier | alter <index> |veriier   // without the angle brackets

	getline(cin,command);
	int i = 0;
	while (i<command.length())
	{
		string remainder , token;
		
		// the position of next |
		int r = command.find('|',i);

		if (r != -1)
		{
			token = command.substr(i,r-i);
			i = r+1;
		}

		else
		{
			token = command.substr(i,token.length() - i);
			i = command.length();
		}
		
		token = trim(token);
		if (token [0] == 'g')
		{
			remainder = Generator (message, gen);
			transmitted_msg = message + remainder;
			transmitted_msg_out = transmitted_msg;
			//outfile<<"transmitted message : "<<transmitted_msg<<endl;
			//cout <<"transmitted message : "<<transmitted_msg<<endl;
		}

		else if (token[0] == 'v')
		{
			bool correct = verifier (transmitted_msg ,gen);
			if(correct)
			{
				correct_msg= "message is correct";
				//cout << "message is correct"<<endl;
				//outfile << "message is correct"<<endl;

			}

			else
			{
				not_correct = "message is not correct";
				//cout << "message is not correct"<<endl;
				//outfile << "message is not correct"<<endl;
			}
		}

		else if (token[0] == 'a')
		{
			int r = token.find(' ',0);
			while (token[r] == ' ')
				r++;

			int index = atoi(token.substr(r,token.length()).c_str());
			alter (transmitted_msg,index);
			altered_msg_out = transmitted_msg ;
			//cout <<"altered message : "<<transmitted_msg<<endl;
			//outfile <<"altered message : "<<transmitted_msg<<endl;
		}
	}*/
	_getch();
	return 0;
}
