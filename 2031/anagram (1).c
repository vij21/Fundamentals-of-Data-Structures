#include<stdio.h>
//#include<conio.h>
#include<string.h>
   // int com_star(char[],char[]);
 //bool are_anagrams(const char *str, const char *str2){
     int anagram(char[],char[]);
     int main()
{
    // array of 26 integers to keep track of how many times each letter (a-z) has been seen
    char a[26];
    
    char b[26];
    
    int flag;

	//ask the user to enter a word
    printf("Enter first word: ");
    scanf("%s",a);
	//ask the user to enter the second word
     printf("Enter second word: ");
     scanf("%s",b);
   
    flag = anagram(a,b);
    //this is checking if two words entered are anagrams or not 
    if (flag == 1){
        printf("The words are anagrams.");
    }else if(flag == 0){
        printf("The words are not anagrams.");
    }
        //getch();
        return 0;
    }
    //stores both words entered earlier as numbers 
   int anagram(char a[],char b[]){
	//check if its a character and get the value of it 
    int first[26]={0};
    int second[26]={0};
    int c=0;

	//this will replace the words into numbers
	//also checks lower case and upper case 
    while(a[c]!='\0'){
        if(a[c]>= 'a' && a[c]<='z'){
            
        
        first[a[c]- 'a']++;
    }
    else if(a[c] >= 'A' && a[c] <= 'Z'){
        first[a[c]-'A']++;
    }
    c++;
    }
    
             c=0;
            while(b[c]!='\0'){
                    if(b[c]>= 'a' && b[c]<='z'){
            
        
        second[b[c]- 'a']++;
    }
    else if(b[c] >= 'A' && b[c] <= 'Z'){
        second[b[c]-'A']++;
    }
    c++;
               
         }
          for (c=0; c<26;c++){
              if(first[c]!=second[c]){
                  return 0;
              }
          }
    return 1;
            
            
            
 }   

   // int main(char str[], str2[]) {
       // while (str[i] == str2[j]){
         //   if(str[i]=="\0" || str2[j]=="\0"){
           //     break;
             //   j++;
            //}
            //if(str[i]=="\0" && str2[j]=="\0"){
              //  return 0;
            //    else
              //  return 1;
            //}
            
    //    } 
        
  


		

//}
			
        



