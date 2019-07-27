#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    string vocab;
    
    vector<string> reCheck;
    
    int reCheckNum = 0;
    
    int lineSeperator = 0;
    
    int vocabNum = 0;
    
    string mean;
    
    string input;
    
    ifstream file;
    
    string choice;
    
    int ans_reveal = 0;
    
    int k = 0;
    
    string u_file;
    
    cout << "enter your vocab file's name(the format of the txt file need to be [vocab 'blank' meaning]): " ;
    
    getline(cin, u_file);
    
    file.open(u_file.c_str());
    
    cout << "Choose a way you want to recite the vocabs:" << endl;
    cout << "                   -Enter vm for vocab to meaning" << endl;
    cout << "                   -Enter mv for meaning to vocab" << endl;
    cout << "Your choice: " ;
    cin >> choice;
    cin.ignore(100,'\n');
    
    int wrongNum = 0;
    
    if ( choice == "mv" )
    {
        
        while ( file >> vocab >> mean )
        {
            ans_reveal = 0;
            vocabNum++ ;
            cout << "what's the vocab of " << mean << " ?: ";
            getline(cin,input);
            while( input != vocab && k == 0){
                if ( reCheckNum == 0 )
                {
                    reCheck.push_back(vocab);
                    reCheck.push_back(" ");
                    reCheck.push_back(mean);
                }
                ans_reveal++ ;
                if ( ans_reveal > 2 )
                {
                    cout << "The right answer is: " << vocab << endl;
                }
                cout << "check your answer, and enter it again (control c to end the process): " ;
                wrongNum++ ;
                getline(cin,input);
                if (input == vocab)
                    //break the loop;
                    k = 1;
                reCheckNum++ ;
            }
            cout << "you are correct" << endl;
            // for while loop execute again.
            k = 0;
            reCheckNum = 0;
        }//END of while ( file >> vocab >> mean )
        
    }
    
    else if ( choice == "vm" )
    {
        while ( file >> mean >> vocab )
        {
            if ( reCheckNum == 0 )
            {
                reCheck.push_back(vocab);
                reCheck.push_back(" ");
                reCheck.push_back(mean);
            }
            ans_reveal = 0;
            vocabNum++ ;
            cout << "what's the meaning of " << mean << " ?: ";
            getline(cin,input);
            while( input != vocab && k == 0){
                ans_reveal++ ;
                if ( ans_reveal > 2 )
                {
                    cout << "The right answer is: " << mean << endl;
                }
                cout << "check your answer, and enter it again: (control c to end the process)" ;
                wrongNum++ ;
                getline(cin,input);
                if (input == vocab)
                    //break the loop;
                    k = 1;
            }
            cout << "you are correct" << endl;
            // for while loop execute again.
            k = 0;
            reCheckNum = 0;
        }//END of while ( file >> vocab >> mean )
    }
    
    else
    {
        cout << "Please Enter the right choice letters" << endl;
        return 120;
    }
    
    cout << "congrats! you finished!" << endl;
    
    cout << "You have recited " << vocabNum << " vocabularies today! " << endl;
    
    cout << "the overall wrong trials calculated by computer are: " << wrongNum << endl;
    
    cout << "By the way, you still get some review cheat sheet to receive -------------------------- " << endl;
    
    for (int i = 0; i < reCheck.size(); i ++)
    {
        if ( lineSeperator > 2 )
        {
            cout << endl;
            lineSeperator = 0;
        }
        cout << reCheck.at(i);
        lineSeperator++ ;
    }
    cout << endl;
    cout << " ------------------------------------------------------ " << endl;
    
    file.close();
    return 0;
    
}



