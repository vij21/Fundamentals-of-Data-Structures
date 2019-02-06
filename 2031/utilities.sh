#!/bin/bash

input () {
clear



echo —————————————————————————————————————
echo M A I N - M E N U
echo —————————————————————————————————————-
echo 1. Ongoing Processor Activity
echo 2. Users Currently Logged In  
echo 3. Number Of users Currently Logged In
echo 4. Users with bash shell
echo 5. Exit
echo ——————————————————————————————————————


	

	#promt the user to input a value between 1-5
	echo -n Please Enter Option [1 - 5]:; read i

	case $i in
		#Press Q to get back to the screen
		1) top ;; 
		2) who ;;
		3) who|wc -l ;;
		4) ps aux | grep bash |grep -v grep | cut -d " " -f 1 | sort | uniq ;;
		5) exit ;;
		*) echo You did not choose ;;

		esac



#asking the user to press enter
echo Press [enter] key to continue. . .
read $n  #read the input 

#I did a while loop to read the input which is the enter
while [ $n =  ]

do 

input #this will loop back to the code
 

done 
}

input

 


		
