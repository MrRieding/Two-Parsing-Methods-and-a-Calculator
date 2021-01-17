Parsing Calculator
by O. Otcasek

How do I run this?
-Simply type "make" into the terminal, and then type "./expr" to start the program. 
-If this doesn't work for some reason, I included an executable file.

What does it do?
-This program parses arithmetic expressions from a grammar provided to us.
-The first part of the program creates a parse tree through recursive descent,
-and the second uses the table-driven method. Then, it uses the table-driven method's
-parse tree to calculate the result of what was typed by the user.

Note: the grammar provided to us does not seem to work with negative numbers. Therefore,
this program will not parse "-3+2", but can parse "2-3".

This project was a personal exercise and should obviously not be used dishonestly.