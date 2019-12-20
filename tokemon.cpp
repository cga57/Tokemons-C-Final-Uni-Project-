// PROGRAM CREATED BY CHIRAG GUPTA
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// sizes of 2d arrays
const int NUM_ABILITIES = 5;
const int TOKEMONS = 300; // max tokemons
const int measurements = 2; // weight and height

// constants used for the height_weight array in main
const int HEIGHT = 0; // 1st column of 2d array is height
const int WEIGHT = 1; // 2nd column of 2d array is weight
// constants used for abbilies array
const int FLY = 0;
const int FIRE = 1;
const int WATER = 2;
const int ELECTRIFY = 3;
const int FREEZE = 4;

int toke_counter = 0; // counts how many tokemons there actually are

// Additonal Content: DoublePower/Stronger function which increases
// the power of all of its abbuliites by two

// prints menu
void displayMainMenu(){

    cout << "*************" << endl;
    cout << "* Main Menu *" << endl;
    cout << "*************" << endl;
    cout << "1. List Tokimons" << endl;
    cout << "2. Add a new Tokimon" << endl;
    cout << "3. Remove a Tokimon" << endl;
    cout << "4. Change Tokimon ability" << endl;
    cout << "5. Change Tokimon height" << endl;
    cout << "6. Change Tokimon weight" << endl;
    cout << "7. Exit" << endl;
    // my personal additions to game
    cout << "8. Make Tokimon Stronger(Secret Hack Edition)" << endl;
    return;
}

// displays all Tokemons with their name, measurements and abbilities
void displayAllTokis(string names[], double height_weight[][measurements],
                     int abilities[][NUM_ABILITIES]){



    cout << "*********************" << endl;
    cout << "* List of Tokimons: *" << endl;
    cout << "*********************" << endl;
    // loops through every tokemon
    // using global variable toke_counter
    // for the stop condition
    for (int i = 0; i < toke_counter; i++){
        cout << (i+1) << ". " << names[i] << ", ";
        cout << setprecision(1) << fixed << height_weight[i][HEIGHT] << "cm, ";
        cout << setprecision(1) << fixed << height_weight[i][WEIGHT] << "kg, ";
        cout << "Abilities: fly = " << abilities[i][FLY] << ", ";
        cout << "fire = " << abilities[i][FIRE] << ", ";
        cout << "water = " << abilities[i][WATER] << ", ";
        cout << "electrify = " << abilities[i][ELECTRIFY] << ", ";
        cout << "freeze = " << abilities[i][FREEZE] << endl;
    }
}

// allows the user to add new tokemon
// including its name, height,weight and abbilities
void addNewToki(string names[], double height_weight[][measurements],
                int abilities[][NUM_ABILITIES], string name, double height,
                double weight, int new_abilities[NUM_ABILITIES]) {

    toke_counter++; // add 1 to global variable toke_counter which tracks # of tokemon

    // this variableis the place where the the new tokemon should be stored
    int new_index = toke_counter-1; // subtract 1 since array index start at 0
    names[new_index] = name;
    height_weight[new_index][HEIGHT] = height;
    height_weight[new_index][WEIGHT] = weight;

    // start of the index of new_abilitis array - which stores the abilities
    int counter = 0;

    abilities[new_index][FLY] = new_abilities[counter];
    abilities[new_index][FIRE] = new_abilities[counter+1];
    abilities[new_index][WATER] = new_abilities[counter+2];
    abilities[new_index][ELECTRIFY] = new_abilities[counter+3];
    abilities[new_index][FREEZE] = new_abilities[counter+4];
}
// deletes the nth tokemon
// by deteleting every row and column in every array
// Note: the nth tokemon is (n-1) in array indexes
void deleteToki(int n, string names[], double height_weight[][measurements],
                int abilities[][NUM_ABILITIES]) {

    toke_counter--;
    // Moves everything left 1, this deleting this array
    int k = n-1; // converts the tokemon to delete in terms of array index to delete
    for(int i = 0; i < n-1; i++){

        // moves everything one to the left
        // effectively deleting the k element
        names[k] = names[k+1];
        height_weight[k][HEIGHT] = height_weight[k+1][HEIGHT];
        height_weight[k][WEIGHT] = height_weight[k+1][WEIGHT];
        abilities[k][FLY] = abilities[k+1][FLY];
        abilities[k][FIRE] = abilities[k+1][FIRE];
        abilities[k][WATER] = abilities[k+1][WATER];
        abilities[k][ELECTRIFY] = abilities[k+1][ELECTRIFY];
        abilities[k][FREEZE] = abilities[k+1][FREEZE];
    }
}
// changes a specific tokimon ability by taking the ability to be changed
// as a user input string
void alterTokiAbility(int abilities[][NUM_ABILITIES], string ability_name,
                      int select_tokemon, int new_value){

    // which column in the array should be altered
    // aka which abbility in array format
    int column_to_be_altered = -1; // default value not in range on purpose
                                   // for debugging

    if (ability_name == "fly")
        column_to_be_altered = FLY;
    if(ability_name == "fire")
        column_to_be_altered = FIRE;
    if(ability_name == "water")
       column_to_be_altered = WATER;
    if(ability_name == "electrify")
       column_to_be_altered = 3;
    if(ability_name == "freeze")
        column_to_be_altered = FREEZE;
    // changes the ability
    abilities[select_tokemon-1][column_to_be_altered] = new_value;
}
// changes the toki height to the value the user inputs
void alterTokiHeight(double height_weight[][measurements], double new_height,
                     int select_tokemon){

    height_weight[select_tokemon-1][HEIGHT] = new_height;


}
// changes the toki weight to the value the user inputs
void alterTokiWeight(double height_weight[][measurements], double new_weight,
                     int select_tokemon){

    height_weight[select_tokemon-1][WEIGHT] = new_weight;

}
/* MY PERSONAL FUNCTION - EXTRA ADDITIONS TO PROGRAM */

// This function makes the the tokemon stronger by doubling the POWER
// of ALL its abilities by 2
// CAN WORK AS A CHEAT OF SOME SORT
void double_power(int abilities[][NUM_ABILITIES], int select_tokemon) {
    // the index of the first ability
    int counter = 0;
    // Note: Since this is an array it follows a similar technique
    // to POINT BY POINTER, hence we can alter the array directly
    // and the ACTUAl values will be changed
    abilities[select_tokemon-1][counter]*=2;
    abilities[select_tokemon-1][counter+1]*=2;
    abilities[select_tokemon-1][counter+2]*=2;
    abilities[select_tokemon-1][counter+3]*=2;
    abilities[select_tokemon-1][counter+4]*=2;

}
/* program to store all tokimon data and
 execute various functions that can be applied to the
 the tokemon */

int main(){
    // intial user input
    int user_input;
    // intitialzess all global arrays set to a default values
    int abilities[TOKEMONS][NUM_ABILITIES] = {0,0};
    double height_weight[TOKEMONS][measurements] = {0,0};
    string names[TOKEMONS];

    // takes in user input and displays menu once guaranteed
    // then repeats this whenever condition is true
    // (aka user does not press 7)
    do{
       displayMainMenu(); // prints out intial menu
       cin >> user_input;
       // switch statement is used instead of if-else
       // for shorter code and easy readability
       switch(user_input){

        case 1:
        {
            displayAllTokis(names, height_weight, abilities);
            break;
        }
        case 2:
        {
            string name;
            double height;
            double weight;
            int ability[NUM_ABILITIES]; // only stores the value for abiltiies
                           // of the newly created pokemon
            // user inpuyt and output
            cout << "Enter Tokimon's name: ";
            cin >> name;
            cout << "Enter Tokimon's height: ";
            cin >> height;
            cout << "Enter Tokimon's weight:";
            cin >> weight;
            cout << "Enter abilities (fly, fire, water, electrify, freeze): ";
            cin >> ability[0] >> ability[1] >> ability[2] >> ability[3] >> ability[4];

            // add Tokemon functon call
            addNewToki(names, height_weight, abilities, name, height, weight, ability);
            cout << name << " added succesfully" << endl;
            break;
        }
        case 3:
        {
            displayAllTokis(names, height_weight, abilities);
            cout << "(Enter 0 to cancel)" << endl;
            // input for deletetion (aka Which tokemon to delete?)
            int delete_number;
            cin >> delete_number;
            if (delete_number == 0){
                break;
            }
            deleteToki(delete_number, names, height_weight, abilities);
            break;
        }
        case 4:
        {
            displayAllTokis(names, height_weight, abilities);
            cout << "(Enter 0 to cancel)" << endl;
            int select_tokemon;
            cin >> select_tokemon;
            if (select_tokemon == 0){
                break;
            }
            // user input
            string ability_name;
            int new_value;
            cout << "Which ability? ";
            cin >> ability_name;
            cout << "New Value?     ";
            cin >> new_value;
            alterTokiAbility(abilities, ability_name, select_tokemon, new_value);
            // output
            cout << names[select_tokemon-1] << " now has " << ability_name;
            cout << " ability " << new_value << "!" << endl;
            break;
        }
        case 5:
        {
            // input
            displayAllTokis(names, height_weight, abilities);
            cout << "(Enter 0 to cancel)" << endl;
            int select_tokemon;
            cin >> select_tokemon;
            if (select_tokemon == 0){
                break;
            }
            double new_height;
            cout << "What is the new height? ";
            cin >> new_height;
            alterTokiHeight(height_weight,new_height, select_tokemon);
            // output
            cout << names[select_tokemon-1] << " now has height of ";
            cout << setprecision(1) << fixed << new_height;
            cout << endl;
            break;
        }
        case 6:
        {
            // input
            displayAllTokis(names, height_weight, abilities);
            cout << "(Enter 0 to cancel)" << endl;
            int select_tokemon;
            cin >> select_tokemon;
            if (select_tokemon == 0){
                break;
            }
            double new_weight;
            cout << "What is the new weight? ";
            cin >> new_weight;
            alterTokiWeight(height_weight,new_weight, select_tokemon);
            // output
            cout << names[select_tokemon-1] << " now has weight of ";
            cout << setprecision(1) << fixed << new_weight;
            cout << endl;
            break;
        }
        case 7:
        {
            break; // just exit
        }
        case 8:
        {
            displayAllTokis(names, height_weight, abilities);
            cout << "(Enter 0 to cancel)" << endl;
            int select_tokemon;
            cin >> select_tokemon;
            if (select_tokemon == 0){
                break;
            }
            double_power(abilities,select_tokemon);
            cout << names[select_tokemon-1] << " is now super strong!" << endl;
            break;
        }
        // EXTRA ADDITIONS BY ME (SECOND)
        default:
            exit(-1); // error handling, if user enters number outside of range[1,7]
            break;

      }

    } while(user_input != 7); // 7 is the exit condition

    return 0;
}
