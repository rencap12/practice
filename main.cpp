#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;

int main()
{

   /* Type code here. */
   /* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2

   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces

   Print out data in table format

   Print out data in chart format
   */

   cout << "Enter a title for the data:" << endl;
   string title;
   getline(cin, title);
   cout << "You entered: " << title << endl;

   cout << "Enter the column 1 header:" << endl;
   string column1;
   getline(cin, column1);
   cout << "You entered: " << column1 << endl;

   cout << "Enter the column 2 header:" << endl;
   string column2;
   getline(cin, column2);
   cout << "You entered: " << column2 << endl;

    vector<string> names;
    vector<int> numbers;
    bool key = true;

    while(key) {
        cout << "Enter a data point (-1 to stop input):" << endl;
        string temp;
        int commaCount = 0;

        try {
            getline(cin, temp);
            if (temp == "-1"){
                break;
            }
            for (long unsigned int i = 0; i < temp.length(); i++) {
                char interim = temp.at(i);
                if (interim == ',') {
                    commaCount++;
                }
            }

            if (commaCount > 1) {
                throw runtime_error("Error: Too many commas in input.");
            }
            if (commaCount == 0) {
                throw runtime_error("Error: No comma in string.");
            }
            if (commaCount == 1){
                string holder = temp;
                stringstream ss(temp);
                getline(ss,temp,',');
                names.push_back(temp);

              try {
                  int pos = holder.find(",");
                  string token = holder.substr(pos + 1);
                  int number = stoi(token); //get integer
                  numbers.push_back(number);
                  if(names[names.size() - 1] != temp) {
                      cout << "Data string: " << temp << endl;
                  }
                  cout << "Data integer: " << number << endl;
              }
              catch(exception &e){
                  cout << "Error: Comma not followed by an integer." << endl;
              }
            }
        }
        catch(exception &e) {
            cout << e.what() << endl;
        }
    }
    cout << "\n" ;
    cout << setw(33) << right << title << endl;
    cout << setw(20) << left << column1 << "|" ;
    cout << setw(23) << right << column2 << endl;
    cout << setfill('-') << setw(44) << "" << endl;
    cout << setfill(' ');
    for(long unsigned int i = 0; i < names.size(); i++){
        cout << setw(20) << left << names[i] << "|";
        cout << setw(23) << right << numbers[i] << endl;
    }
    cout << "\n" ;
    for(long unsigned int i = 0; i < names.size(); i++){
        cout << setw(20)<< right << names[i] << " ";
        for(int j = 0; j < numbers[i];j++){
            cout << "*";
            if(j == numbers[i] - 1){
                cout <<"\n";
            }
        }


    }

   return 0;
}