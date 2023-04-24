#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<string>
#include <fstream>
#include <time.h>
using namespace std;

//9/6/2022 Notes on Scopes & Malik,D.S*
//Function prototypes declared first:
void PrintList(int array[], int size, string list);
void PrintList (string array[], int size, string list);
void FilePrintList (string array[], int size);
int RandomInt(int ceiling);
int GetSize();
void Menu();
void Map(int shuffled[], string array[], int size);
bool TestDeck(int array[], int size);
void CreateDeck(string array[], int size);


int main(){
    srand (time(NULL)); //Randomized Shuffled Numbers & Cards
    Menu(); //Main will call from void Menu()
}


//DECLARATION OF FUNCTIONS
//Accepts array of ints,size of array,and string
void PrintList(int array[], int size, string list){
cout << list << endl; //Outputs list
for(int i=0; i< size; i++) //Printing deck size
    cout<< array[i]<<endl;
cout<< endl;
}
//Accepts string array, size and a string
void PrintList(string array[], int size, string list){
cout<<list<<endl;
for(int i=0; i<size; i++)
    cout<< array[i]<< endl;
cout<< endl;
}

void FilePrintList(string array[], int size){
//output deck to file, if the test is successful
    string filename;
    cout<<"Enter file name: ";
    cin>>filename; //User input
    ofstream myfile(string(filename).c_str()); //Output file is created and printed
        if(myfile.is_open()){
            for(int i=0; i<size; i++)
            myfile<<array[i]<<endl;
    }
        else
            cout<<"File could not open\n";
            myfile.close();
    }
//Ceiling integer only
int RandomInt(int ceiling){
    return rand()% ceiling; //Random integer representing an index
}
//Gets user input to select number of cards in deck
int GetSize(){
int size = -1;
enterCards:
cout<<"Enter Number of Individual Cards: "; //in standard deck 13 cards: Ace, 2, 3, 4, 5, ... Jack, Queen, King
cin>>size;
if(size<5 || size>13) //If cards are out of scope, prompt user for another input
{
cout<<"Values should be in range between 5 and 13 "<<endl;
goto enterCards; //Loops back to beginning of input prompt
}
return size; //Get size of deck back
}

void Menu(){
int action = -1; //action allows us to navigate  the menu, we choose 0 to exit,1 to create a deck of cards
    while(action!=0){ //Until valid input is called, prompt user to input 1 or 0 only

//***Left system (CLS) commented out as it runs faster***
        //system("CLS"); //this clears the screen
        //Display manipulation
        cout<<setw(20)<<"Menu"<<endl;
        cout<<setw(30)<<std::left<<"Create Deck of Cards: "<<"1\n";
        cout<<setw(30)<<std::left<<"Exit: "<<"0\n";
        reenter: //if we select an invalid menu item, we return here
        cout<<"Action: ";
        cin>> action; //User is prompted for 1 or 0
        cout<<endl;
        if(action == 1){ //if user wants to create deck of cards
            int size = GetSize(); //Will set size to the return type of GetSize().
        string cards[size*4]; //create an array for actual deck, which has 4 of each card

    CreateDeck(cards,size); //Calls prototype to execute function CreateDeck with GetSize result
        cout<<"Map Successful\n\n"; //Verifies conversion
        PrintList(cards,size*4, "Shuffled Cards:"); //Prints array
        FilePrintList(cards,size*4);
    }
        else if(action == 0){
            break; //If user inputs 0, stop program
        }
        else{
                cout<<"Please enter valid Menu item\n"; //All unaccounted inputs will ask for reentry
                goto reenter; //Jumps back to line 84
            }
    }
}
//Converts integers into cards
void Map(int shuffled[],string cards[], int size){
//Until i is less than size of card deck, increment by 1 (starting at 0)
                for(int i=0; i<size; i++){
 //Covert the array of integers "shuffled to corresponding strings
                    if(shuffled[i] == 0)
                        cards[i]= "1";
                    else if(shuffled[i] == 1)
                        cards[i]= "2";
                    else if(shuffled[i] == 2)
                        cards[i]= "3";
                    else if(shuffled[i] == 3)
                        cards[i]= "4";
                    else if(shuffled[i] == 4)
                        cards[i]= "5";
                    else if(shuffled[i] == 5)
                        cards[i]= "6";
                    else if(shuffled[i] == 6)
                        cards[i]= "7";
                    else if(shuffled[i] == 7)
                        cards[i]= "8";
                    else if(shuffled[i] == 8)
                        cards[i]= "9";
                    else if(shuffled[i] == 9)
                        cards[i]= "10";
                    else if(shuffled[i] == 10)
                        cards[i] = "J";
                    else if(shuffled[i] == 11)
                        cards[i] = "Q";
                    else if(shuffled[i] == 12)
                        cards[i] = "K";
        else{
            cout<<"Something wrong\n";
            cout<<"at index "<<i<<" found card "<<cards[i]<<endl;
            exit (EXIT_FAILURE);
            }

    }

}

bool TestDeck(int array[], int size){
int counter = 0;
//cycle through the numbers representing our cards
for(int i=0; i<size/4; i++){ //Forces 4 of each card
    counter = 0;
//for each number, go through the whole array and count how many times we see it
    for(int j = 0; j<size; j++){
        if(array[j] == i)
        counter++;
        }
    if(counter != 4){ //if we did not see it 4 times, we did something wrong
    cout<<"Shuffle Wrong "<<i<<" not properly assigned";
    cout<<"Found "<<counter<<" times in shuffled list\n";
    return false; //Stops program
    }
    else //otherwise, all good, but output this to let us know our test is working
    cout<< i<<" found "<<counter<<" times"<<endl;
}
return true;
}

void CreateDeck(string array[] ,int size){
     int avail_cards[size];  //keeps a list of the cards we can put in our deck, if a card is used 4 times
     int current_size = size; //this variable will be decremented
     int times_card_used[size]; //this is used for the shuffling, lets us know how many times we have used each card as we move it to our final, shuffled deck
     int shuffled[size*4]; // array for our deck, with each integer representing a different card
        for(int i=0; i< size; i++) //initialize array
                avail_cards[i] = i;
        for(int i=0; i< size; i++) //initialize array
                times_card_used[i] = 4;
        int temp_index = -1;
        for(int i=0; i<size*4; i++){
            temp_index = RandomInt(current_size); // get random index
            shuffled[i]= avail_cards[temp_index];   //use that random index, to see which card to insert at shuffled[i]
            times_card_used[avail_cards[temp_index]]--; //mark that we used that card
                //used index is "removed" from the list by shifting the numbers
                //then a current_size variable let's us know how much of array we can use
                //later in the course, you can use dynamic arrays to actually shrink the array
                //instead of keeping track with the current_size

        if(times_card_used[avail_cards[temp_index]] == 0){
            for(int j = temp_index; j < current_size-1; j++)
            avail_cards[j]= avail_cards[j+1];
            current_size--;
            }
        }
//Calls for array to be printed
PrintList(shuffled, size*4, "Shuffled Numbers:");

    cout<<"Testing\n";
    //we test to see if our card deck has the right number of each card
    bool pass = TestDeck(shuffled,size*4); //Calls TestDeck() and expects a return value of "true"
      if(!pass){ //If return value != true, test has failed and program will end
        cout<<"Test failed\n";
        exit(EXIT_FAILURE);} //Program is terminated

        cout<<"Test successful\n\n"; //If return value == true, program proceeds to convert cards in deck in Map() to be printed
        Map(shuffled,array,size*4);
}

// LEARNING MATERIALS USED:
//Malik, D. S. (2018). In C++ programming: From Problem Analysis to Program Design
//(pp. 360–367),Cengage Learning (Hard Copy)
//Lecture notes from 9/6/2022: Scope & Structures
