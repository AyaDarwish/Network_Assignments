The goal of this lab exercise:
===============================
implement an error-detection mechanism using the standard CRC algorithm described in the text. 
Write two programs, generator and verifier. 

 The generator program reads from standard input a line of ASCII text containing an m-bit message consisting of a string of 0s and 1s. The second line is the k-bits polynomial, also in ASCII. It outputs to standard output a line of ASCII text with (m+k) 0s and 1s representing the message to be transmitted. Then it outputs the polynomial, just as it read it in. 

 The verifier program reads in the output of the generator program and outputs a message indicating whether it is correct or not. 

 Finally, write a program, alter, that inverts 1 bit on the first line depending on its argument (the bit number counting the leftmost bit as 1) but copies the rest of the two lines correctly. By typing generator <file | verifier you should see that the message is correct,  but by typing generator <file | alter arg | verifier you should get the error message. 
