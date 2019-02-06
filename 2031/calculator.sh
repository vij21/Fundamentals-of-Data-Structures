#!/bin/bash


#if [ “$2” = “+” ] || [ “$2” = “-“ ] || [ “$2” = “x” ] || [ “$2” = “/“ ]];
		#then
		#if the user input + as the second variable it would add
		if [ “$2” == “+” ]
			then
			sum=$(($1 + $3))
			echo $sum 
		#if the second input is - then subtract
		elif [ “$2” == “-” ]
			then
			difference=$(($1 - $3))
			echo $difference	
		#if the third input is x then multiply 
		elif [ “$2” == “x” ]
			then
				mult=$(($1 * $3))
				echo $mult
		#if the fourth input is / then divide
		elif [ “$2” == “/” ]
			then
				if [ $3 -eq 0 ] #checking if the 3rd value is a zero and send an error if it is 
					then
					echo “Division-by-zero Error!”
				else 
					div=$(($1 / $3))
					echo $div
				fi
		
		##fi
		
		else
		echo “Usage - ./calculator.sh value1 operator value2”
		echo “where,”
		echo “value1: numeric value”
		echo “value2: numeric value”
		echo “operator: one of +, -, /, x”
fi

			
				