//
// EECS2031 team.c
//
// Program for maintaining a personal team.
///
//
// Author: <Sharumilan Vijayaratnam>
// Student Info: <213656962>


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

//**********************************************************************
// Linked List Definitions 
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//
//   ADD STATEMENT(S) HERE

//Structure for Player datatype, contains family name, first name, position, value and
//teammate pointing to 
struct Player {
char * family_name;
char * first_name;
char position;
int value;
struct Player * next; 
};

//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE

struct Player *Insertsort(struct Player* head,char family_name[],char first_name[],int value, char position);

//void delete(struct Player* head,char family_name[]);
struct Player *delete(struct Player* head,char x[]);


struct Player* findFamily(struct Player* head,char *family_name);

void search_less_equal_value(struct Player * head, int value);


struct Player * quit(struct Player * head);
void findLast(struct Player* head,char family_name[]);

void print_player(struct Player* player) ;
int to_non_negative_number(char number[]);
struct Player * quit(struct Player * head);

void print_team(struct Player * head);



bool contains_duplicate(struct Player * head, char family_name[]);

//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void familyNameDuplicate (char familyName[]);   // marker/tester friendly 
void familyNameFound (char familyName[]);       //   functions to print
void familyNameNotFound (char familyName[]);    //     messages to user
void familyNameDeleted (char familyName[]);
void printTeamEmpty (void);
void printTeamTitle(void);
void printNoPlayersWithLowerValue(int value);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char GOALKEEPER = 'G';
const char DEFENDER = 'D';
const char MIDFIELDER = 'M';
const char STRIKER = 'S';


//**********************************************************************
// Main Program
//

int main (void)
{ 
    const char bannerString[]
        = "Personal Team Maintenance Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  V (search by value), P (print), Q (quit).\n";

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE link LIST HEAD.
    struct Player *head = NULL;



  // announce start of program
    printf("%s",bannerString);
    printf("%s",commandList);
    
    char response;
    char input[MAX_LENGTH+1];
    do
    {
        printf("\nCommand?: ");
        safegets(input,MAX_LENGTH+1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            // Insert a player entry into the linked list.
            // Maintain the list in correct order (G, D, M, S).
            //   ADD STATEMENT(S) HERE
//variables for storing player information
char family_name[MAX_LENGTH+1];
char first_name[MAX_LENGTH+1];
char position; 
int value;
char ch;
bool invalid_position= false;
// USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
            printf(" family name: ");
safegets(family_name,MAX_LENGTH+1); // gets family name
    printf("  first name: ");
safegets(first_name,MAX_LENGTH+1); // gets first name

              printf("  position: "); //get position
    scanf("%c", &position);
           
printf("  value: ");
scanf("%d",&value); // gets value
if(findFamily(head,family_name)!=NULL){ //checks duplicate name in list
familyNameDuplicate(family_name);
response=getchar();
} 

else{
head=Insertsort(head,family_name,first_name,value,toupper(position));
response=getchar();
}
}
        else if (response == 'D')
        {
            // Delete a player from the list.
char family_name[MAX_LENGTH+1];

            printf("\nEnter family name for entry to delete: ");
   //   ADD STATEMENT(S) HERE
safegets(family_name,MAX_LENGTH+1);

if(findFamily(head,family_name)==NULL){ // if the list is empty then theres no names so print error
familyNameNotFound(family_name);
}
else{
head=delete(head,family_name); //delete
familyNameDeleted(family_name);
}
        }
        else if (response == 'S')
        {
            // Search for a player by family name.
  //   ADD STATEMENT(S) HERE
char family_name[MAX_LENGTH+1];
            printf("\nEnter family name to search for: ");
safegets(family_name,MAX_LENGTH+1);
//find the player by their family name
if (findFamily(head,family_name)!=NULL){ // if its true 
familyNameFound(family_name);
}
else{
familyNameNotFound(family_name); //else

}

}
        else if (response == 'V')
        {
            // Search for players that are worth less than or equal a value.
char val[MAX_LENGTH+1];

  printf("\nEnter value: ");

safegets(val,MAX_LENGTH+1);
            //   ADD STATEMENT(S) HERE


//scanf("%d",&value);
int value = atoi(val);// change from char to int



search_less_equal_value(head,value); //get value 
if (head==NULL){
 printNoPlayersWithLowerValue(value); //if head is == null then theres no values
 
}
/*else{

findFamily(head,value);
}
response=getchar();

}*/}
        else if (response == 'P')
        {
            // Print the team.

            //   ADD STATEMENT(S) HERE
            //print_team(head);


if(head == NULL){ //if head is null then team is empty and print empty error
printTeamEmpty();


}
else{

printTeamTitle();
print_team(head);


}
        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        else 
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n",commandList);
        }
    } while (response != 'Q');
  
    // Delete the whole link list that hold the team.
    //   ADD STATEMENT(S) HERE
  struct Player* current;
while (head != NULL)
    {
       current = head;
       head= head->next;
       free(current);
    }
    // Print the link list to confirm deletion.
    //   ADD STATEMENT(S) HERE
print_team(head);
if(head == NULL){
printTeamEmpty();
}    return 0;

}
//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize-1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name 
// that is already in the book.
void familyNameDuplicate (char familyName[])
{
    printf("\nAn entry for <%s> is already in the team!\n"
           "New entry not entered.\n",familyName);
}

// Function to call when a player with this family name was found in the team.
void familyNameFound (char familyName[])
{
    printf("\nThe player with family name <%s> was found in the team.\n",
             familyName);
}

// Function to call when a player with this family name was not found in the team.
void familyNameNotFound (char familyName[])
{
    printf("\nThe player with family name <%s> is not in the team.\n",
             familyName);
}

// Function to call when a family name that is to be deleted
// was found in the team.
void familyNameDeleted (char familyName[])
{
    printf("\nDeleting player with family name <%s> from the team.\n",
             familyName);
}

// Function to call when printing an empty team.
void printTeamEmpty (void)
{
    printf("\nThe team is empty.\n");
}

// Function to call to print title when whole team being printed.
void printTeamTitle (void)
{
    printf("\nMy Team: \n");
}

// Function to call when no player in the team has lower or equal value to the given value
void printNoPlayersWithLowerValue(int value)
{
printf("\nNo player(s) in the team is worth less than or equal to <%d>.\n", value);
}

//**********************************************************************



//**********************************************************************
// Add your functions below this line.







struct Player *Insertsort(struct Player* head,char family_name[],char first_name[],int value, char position){
//create new player
struct Player *po;



po = (struct Player *)malloc(sizeof(struct Player));
 // save player information into new node 
po->family_name=malloc(MAX_LENGTH+1);
po->first_name=malloc(MAX_LENGTH+1);
strcpy(po->family_name,family_name);
strcpy(po->first_name,first_name);
   po->value= value;
   po->position = position;

 //if head is empty any player can be inserted first
 if(head == NULL ) {
  po->next=head;
  head = po;
  return head;
 } 

else {  

//from here list is not empty so we insert in special order
//check which player was inserted by position
switch(po->position) {

 
        //new player is Goalkeeper
        case 'G' :
            //head exist you and not G, you add new player to the front
            if((*head).position!='G'){
                po->next=head;
                head=po;
            }else{
                struct Player * walk = head;
                //walk till you see null, or when you see last goalie then add to last goalie
                while((*walk).next!=NULL&&(*(*walk).next).position=='G'){
            walk=(*walk).next;
                }
                (*po).next=(*walk).next;
                (*walk).next=po;
            }
            break;
        //new player is Defender
        case 'D' :
            //head exist you and it is a M or S, you add new player to the front
            if((*head).position=='M'||(*head).position=='S'){
                (*po).next=head;
                head=po;
            }else{
                struct Player * walk = head;
                //walk till you see null, or when you see null M or S, then add
                while((*walk).next!=NULL&&(*(*walk).next).position!='M'&&(*(*walk).next).position!='S'){
            walk=(*walk).next;
                }
                (*po).next=(*walk).next;
                (*walk).next=po;
            }
            break;
        //new player is Midfielder
        case 'M' :
            //head exist you and it is a S, you add new player to the front
            if((*head).position=='S'){
                (*po).next=head;
                head=po;
            }else{
                struct Player * walk = head;
                while((*walk).next!=NULL&&(*(*walk).next).position!='S'){
            walk=(*walk).next;
                }
                (*po).next=(*walk).next;
                (*walk).next=po;
            }
            break;
        case 'S' :
        //new player is Striker
        //you always add the striker to the end
            if(1){
                struct Player * walk = head;
                while((*walk).next!=NULL){
            walk=(*walk).next;
                }
                (*walk).next=po;
            }
            break;
        default :
            free((*po).family_name);
            free((*po).first_name);
            free(po);
            printf("Invalid Position, must be either 'G', 'D', 'M', or 'S'\n" );
   }
    return head;
}


}









//function to delete a player from team
struct Player *delete(struct Player* head,char family_name[]){
  //start from first player
   struct Player* current= head;
   struct Player* previous = NULL;
  //check if list is empty
   if(head == NULL) {
      return NULL;
   }
   
  //go through list to comparing players' last names
 while(strcmp(current->family_name,family_name) != 0) {
//check if it is last player
      if(current->next == NULL) {
         return NULL;
      }
       else {
         //if not keep moving
         previous = current;
         current = current->next;
      }
   }
//last name is found so delete this current player
  if(current == head) {
      //change first to point to next next
      head = head->next;
   } 
else {
      previous->next = current->next;
   }    
return head;
} 













//Searching for player with family name


struct Player* findFamily(struct Player* head,char *family_name){
//point to start of list
struct Player* current = head;
//check if list is empty
   if(head == NULL) {
      return NULL;
   }


//from beginning go through list until the last is the same as a player's family name
   while(strcmp(current->family_name,family_name) != 0) {
//check if last player reach without found 
      if(current->next == NULL) {
         return NULL;
      } 
     else {
         //go to next player
         current= current->next;
      }
   }      
//return this player
findLast(head, current->family_name);
   return current;
} 


void findLast(struct Player* head,char family_name[]) {
  struct Player *current= head;
if(head==NULL){
return;
}
   //start from the beginning
   while(current!=NULL) {
/*check if each player if their value is less or equal to an input value*/
if(strcmp(current->family_name,family_name)==0){
printf("\n");
printf(" %s\n", current->family_name);
printf(" %s\n", current->first_name);
    printf(" %c\n", current->position);
printf(" %d", current->value);
printf("\n");
      
}
current =   current->next;
}







}




//prints players less than specified value
void search_less_equal_value(struct Player * head, int value){
    bool players_found = false;
    struct Player * walk = head;
    while(walk!=NULL){
        if((*walk).value<=value){
            print_team(walk);
            players_found = true;
        }
        walk = (*walk).next;
    
    if(!players_found){ 
printNoPlayersWithLowerValue(value);
}
}

}
/*

//quit, delete linked list
// free up memory
struct Player * quit(struct Player * head){
    struct Player * to_be_freed;
    while(head!=NULL){
        to_be_freed = head;
        head = (*head).next;
        (*to_be_freed).next = NULL;
        free((*to_be_freed).family_name);
        free((*to_be_freed).first_name);
        free(to_be_freed);
    }
    to_be_freed=head;
    return head;
}

*/










//print the team
void print_team(struct Player * head){
    if(head==NULL){
        printTeamEmpty();
    } else {
        //printTeamTitle();
        struct Player * walk = head;
        while(walk!=NULL){
            //calls print player
            //print_player(walk);
printf("\n%s\n",(*walk).family_name);
//prints first name 
    printf("%s\n",(*walk).first_name);
//prints position
    printf("%c\n",(*walk).position);
//prints the value
    printf("%d\n",(*walk).value);


            walk=(*walk).next;
        }
    }
}


//prints the inidvidual player 
void print_player(struct Player *player){
}







//checks non negative number 
/*it will return a postive integer representation of a string only if the string is a number and nonnegative, otherwise will return a number less than 0*/
int to_non_negative_number(char number[]){
bool isNumber = true;
int sum = 0;
int index = 0;
int summation=0;
while(number[index]!='\0'&&index< MAX_LENGTH){
if(number[index]<'0'||number[index]>'9'){isNumber=false;}

summation = summation*10+(number[index]-'0');


index++;
}
return isNumber?summation:-1;
}








// checks for duplicate family name

bool contains_duplicate(struct Player * head, char family_name[]){
    struct Player * walk = head;
    while(walk!=NULL){
        if(strcmp((*walk).family_name,family_name)==0){
            return true;
        }
        walk=(*walk).next;
    }

    return false;


}