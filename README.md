# An implementation for a database in C. 

Collaborators:
Minh 
Shun 
Fenway

Note on project:
+ In the tuple definition, I used pointers instead of char array (char* instead of char[20] for example), and I HAVE ASKED the professor about this.
He said that I can use the pointers for the tuples for the project.

How to build the project AND how to run the project:
Short description: I basically used the school's csug to run my project
Steps:
0. Go to https://accounts.csug.rochester.edu/ and create an account, set up your username and password. REMEMBER your password
1. Download WindSCP from: https://winscp.net/download/WinSCP-5.21.3-Setup.exe
2. Set up WindSCP
3. Open up WindSCP
4. Log into the server with
 + Hostname: cycle1.csug.rochester.edu (or other server of your choices that can be viewed from log into your account in
 https://accounts.csug.rochester.edu/)
 + Your username(NetID) and password.
5. You will see a collection of files in your computer and the collection of file of a virtual machine, find my file in WindSCP
- main.c, part1.h, part3.h, init.h, CRD.h - and use the mouse drag the file from the left screen to the right screen. Drag from your computer to the virtual
machine
6. Keep this WindSCP window open
(Optional: 7. Go to: https://accounts.csug.rochester.edu/ and log into your account)
8. Run the command on the commandline:  ssh -l [YOUR NetID] cycle1.csug.rochester.edu
(for example, I would have: ssh -l mnguy31 cycle1.csug.rochester.edu)
9. Enter your password (the password won't be showing, but you are actually typing it in)
10. Enter into the commandline: $ gcc -std=c99 -Wall -Werror main.c -o e (This line contain all the required compiler option)
11. Enter:  ./e
(In the case that step 7 don't work, Enter ls and see the result. You should see main.c [sth] www. Try ./[sth]. For example, if
[sth] = a, then try ./a)
12. The program should be running by then.
13. Once run, look at prints of part 1, enter strings into part 2 and look at prints of part 3 to find out the results.
