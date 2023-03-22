/**------------------------------------------

    Program 1: Layered Pine Tree
    Prompt for the number of tree layers and display
    ASCII layered pine tree

    Course: CS 141, Fall 2022.
    System: MacOS and G++
    Author: Dr. Sara Riazi
 ---------------------------------------------**/

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.

using namespace std; // so that we don't need to preface every cin and cout with std::

int main()
{
    // Display the menu and get the user choice
    int menu_option = 0;
    cout << "Program 1: The Pine Tree            \n"
         << "Choose from the following options:  \n"
         << "   1. Display the HELLO graphic  \n"
         << "   2. Display The Pine Tree        \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menu_option;

    if (menu_option == 3) { // Handle menu option of 3 to exit
        exit(0); // The call to exit the code successfully (0 means the runs didn't encounter any problem).  
    }

    else if (menu_option == 1) { // Handle menu option of 1 to display custom ASCII graphics
        // Display ASCII graphics for "HELLO".  
        // The main purpose of this part is to give you hints about usnig setw and setfill and their behaviors.

        //the character for the frame of our display.
        char frame = '-';
        cout << "Enter your frame character: ";
        cin >> frame;
        cout << endl;
        // The goal of next three lines is to print a line with 77 dashes differently.
        cout << setfill(frame); //change the default character for filling the fields defined using setw. You can change it fill to different character to see the difference.
        cout << setw(78) << "\n"; // \n counts in 78 so you will get 77 dashes plus one \n  
        cout << setw(78) << endl; ///after setfill you need to pass a string or character to push setfil to fill the field, otherwise you will see an empty line for this instruction. See the differnce in output from this line and the above line. 
        cout << setw(77) << frame << endl; //I use 77 with setfill and one extra at the end to get the same result

        cout << setw(8) << " " << "   **    **    ********    **         **         ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    **         **         ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    **          **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   ********    ********    **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   ********    ********    **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    **          **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    ********   ********   ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    ********   ********   ********    " << setw(9) << "\n";
        cout << setw(77) << frame << endl; //the extra character is - so in total we will have 77 dashes.
        cout << setw(78) << "\n"; //again, the extra character is \n so you have set the width to 78	

        //you can do it this way using a for-loop too
        for (int i = 0; i < 77; i++) {
            cout << frame;
        }
        cout << endl;



    } else if (menu_option == 2) {
        // Prompt for and get the number of layers for the tree.
        int number_of_tree_layers = 0;
        cout << "Number of tree layers -> ";
        cin >> number_of_tree_layers;

        cout << endl; //do not remove this line. It is essential for the autograder!


        int spaceTop = 2+(number_of_tree_layers-1);  // initialized spacing for top subLayer of the star
        int spaceMiddle = 1+(number_of_tree_layers-1); // initialized spacing for Middle subLayer of the star
        int spaceBottom = 0+(number_of_tree_layers-1); // initialized spacing for Bottom subLayer of the star
        string subLayer1 = "*";
        string subLayer2 = "***";         // using strings to store the asterisks
        string subLayer3 = "*****";

        int i = 0; // initialsing a variable for the while loop


        // hard coding the first layer because of limitations in the setw() function found in the while loop
        if (number_of_tree_layers == 1){
            cout<< setw(spaceTop)<<" "<< subLayer1<<endl;
            cout<< setw(spaceMiddle)<<" "<< subLayer2<<endl;
            cout<< subLayer3<<endl;
            cout<< setw(number_of_tree_layers)<<" "<<"|||"<<endl;
            cout<< setw(number_of_tree_layers)<<" "<<"|||"<<endl;

        }
        else{
        cout<< setw(spaceTop)<<" "<< subLayer1<<endl;
        cout<< setw(spaceMiddle)<<" "<< subLayer2<<endl;
        cout<< setw(spaceBottom)<<" " << subLayer3<<endl;

        // adding asterisks and adjusting spaces using while loop
        while(i<number_of_tree_layers){
            spaceBottom --;
            spaceMiddle -- ; // left aligning
            spaceTop --;
            subLayer1 += "**";
            subLayer2 += "**"; // adding asterisks
            subLayer3 += "**";
            i++;

            // for all the layers except the bottom layer
            if (spaceBottom > 0){
                cout<< setw(spaceTop)<<" "<< subLayer1<<endl;
                cout<< setw(spaceMiddle)<<" "<< subLayer2<<endl;
                cout<< setw(spaceBottom)<<" "<<subLayer3<<endl;
            }
            // for the bottom layer
            else if (spaceBottom == 0){
                cout<< setw(spaceTop)<<" "<< subLayer1<<endl;
                cout<< setw(spaceMiddle)<<" "<< subLayer2<<endl;
                cout<< subLayer3<<endl;
            }
        }
            // printing the trunk of the tree
            for (int trunk = 0;trunk<number_of_tree_layers;trunk+=1){

                cout<< setw(number_of_tree_layers)<<" "<<"|||"<<endl;
                cout<< setw(number_of_tree_layers)<<" "<<"|||"<<endl;

            }
    } }


    cout << endl; 

    return 0;
}