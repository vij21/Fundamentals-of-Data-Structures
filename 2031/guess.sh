#!/bin/bash
echo “Welcome to the number game”
echo “Guess a number between 1 and 64” 
rand=$(($RANDOM%64))
i=1
while [ $i -le 6 ] #while the count is less than 6 
do
read numberGuess	

		if [ $numberGuess -lt $rand ] #if the inputted number is less than the randomly generated number then do this
			then
				echo “Too Small.”
				echo “Try Again.”
				i=$(($i+1))
		elif [ $numberGuess -gt $rand ] #if it is bigger than the rand then do this
			then
				echo “Too Big”
				echo “Try Again.”
				i=$(($i+1))
		else
			echo “You Won!”
			exit 1 
			
	fi
done
echo “You lost” 
exit 1

