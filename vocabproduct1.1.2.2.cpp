/***************************************************************************************
 *                                                                                     *
 *                             Creator: Cieas Chen/Cheligeman                          *
 *                                      Upload Date: Oct 19th.                         *
 *                                      Version 1.1.2.2                                *
 *                                                                                     *
 ***************************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// /Users/a1209899754/desktop/word.txt
// /Users/a1209899754/desktop/review.txt
int main(){
    /***************************************************************************************
     *                                                                                     *
     *                             parameter declaration                                   *
     *                                                                                     *
     *                                                                                     *
     *                                                                                     *
     ***************************************************************************************/
    vector<string> reCheck;
    string fileName = "unknown";
    ofstream outputFile;
    bool continues = true;
    int storeReview = 0;
    while (continues) {
        //interface input.
        cout << "           Vocabulary Recitation Program" << endl;
        cout << "                               - written by Cieas Chen" << endl;
        cout << "              P: Start a new program." << endl;
        cout << "              R: Start a review section." << endl;
        cout << "              Q: Quit the program." << endl;
        cout << endl;
        cout << "Choice:" ;
        char enter = '?';
        cin >> enter;
        cin.ignore(10000,'\n');
        
        if ( enter == 'P' || enter == 'p' )
        {
            storeReview = 0; //in case there are mutiple projects to run and because the initial initialization only run for one time.
            cout << endl;cout << endl;
            cout << "Enter the new project section -- " << endl;
            cout << endl;cout << endl;
            /***************************************************************************************
             *                                                                                     *
             *                             parameter declaration                                   *
             *                                                                                     *
             *                                                                                     *
             *                                                                                     *
             ***************************************************************************************/
            string vocab;
            
            const string LONGLINE = "*********************************************";
            
            
            int score = 0;
            
            double finalScore = 0.0;
            
            int reCheckNum = 0;
            
            double wrongScore = 0;
            
            double percent = 0.0;
            
            int lineSeperator = 0;
            
            int vocabNum = 0;
            
            int incorrectNum = 0;
            
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
            /***************************************************************************************
             *                                                                                     *
             *                             execution part                                          *
             *                                                                                     *
             *                                                                                     *
             *                                                                                     *
             ***************************************************************************************/
            if ( choice == "mv" )
            {
                reCheck.clear();// reuseable
                while ( file >> vocab >> mean )
                {
                    score++ ;
                    ans_reveal = 0;
                    vocabNum++ ;
                    int wrongLimit = 0;
                    cout << "what's the vocab of " << mean << " ?: ";
                    getline(cin,input);
                    int limitTrial = 0;
                    while( input != vocab && k == 0){
                        if ( reCheckNum == 0 )
                        {
                            reCheck.push_back(vocab);
                            reCheck.push_back(" ");
                            reCheck.push_back(mean);
                            reCheck.push_back(" ");  //in case the format get mess up.
                        }
                        ans_reveal++ ;
                        if ( ans_reveal > 2 )
                        {
                            //for avoiding multiple subtracting.
                            if ( wrongLimit == 0 )
                            {
                                wrongScore++ ;
                                incorrectNum++ ;
                            }
                            wrongLimit++ ;
                            cout << "The right answer is: " << vocab << endl;
                        }
                        cout << "check your answer, and enter it again (control c to end the process): " ;
                        wrongNum++ ;
                        getline(cin,input);
                        
                        limitTrial = ans_reveal; // for elimiting the another ++ command.
                        
                        if (input == vocab)
                            //break the loop;
                            k = 2;
                        else
                        {
                            if ( limitTrial > 4 )
                                k = 1; // END the program in case the user feel extreme frastrated about infinite loop of trails.
                        }
                        
                        
                        reCheckNum++ ;
                    }
                    if ( k == 2 || k == 0 )
                        cout << "you are correct" << endl;
                    else
                        cout << "you have tried so many times, move to the next one!" << endl;
                    // for while loop execute again.
                    k = 0;
                    reCheckNum = 0;
                }//END of while ( file >> vocab >> mean )
                
            }
            
            else if ( choice == "vm" )
            {
                reCheck.clear();// reuseable
                while ( file >> mean >> vocab )
                {
                    score++ ;
                    int wrongLimit = 0;
                    int limitTrial = 0;
                    ans_reveal = 0;
                    vocabNum++ ;
                    cout << "what's the meaning of " << mean << " ?: ";
                    getline(cin,input);
                    while( input != vocab && k == 0){
                        if ( reCheckNum == 0 )
                        {
                            reCheck.push_back(vocab);
                            reCheck.push_back(" ");
                            reCheck.push_back(mean);
                            reCheck.push_back(" ");  //in case the format get mess up.
                        }
                        ans_reveal++ ;
                        if ( ans_reveal > 2 )
                        {
                            if ( wrongLimit == 0 )
                            {
                                wrongScore++ ;
                                incorrectNum++ ;
                            }
                            wrongLimit++ ;
                            cout << "The right answer is: " << vocab << endl;
                        }
                        cout << "check your answer, and enter it again: (control c to end the process)" ;
                        wrongNum++ ;
                        getline(cin,input);
                        
                        limitTrial = ans_reveal; // for elimiting the another ++ command.
                        
                        if (input == vocab)
                            //break the loop;
                            k = 2;
                        else
                        {
                            if ( limitTrial > 4 )
                                k = 1; // END the program in case the user feel extreme frastrated about infinite loop of trails.
                        }
                    }
                    if ( k == 2 || k == 0)// deleting the ans_reveal <= 4 in case when input = vocab but ans_reveal = 5.
                        cout << "you are correct" << endl;
                    else
                        cout << "you have tried so many times, move to the next one!" << endl;
                    // for while loop execute again.
                    k = 0;
                    reCheckNum = 0;
                }//END of while ( file >> vocab >> mean )
            }
            
            else
            {
                cout << "Please Enter the right choice letters" << endl;
                continue;
            }
            
            percent = (score - wrongScore) / score;
            
            finalScore = 100.0 * percent;
            
            cout << LONGLINE << endl;
            
            cout << "congrats! you finished!" << endl;
            
            cout << "You have recited " << vocabNum << " vocabularies today! " << endl;
            
            cout << LONGLINE << endl;
            
            cout << "the overall wrong trials calculated by computer are: " << wrongNum << endl;
            
            cout << "the overall vocabulary numbers you currently couldn't recite it are: " << incorrectNum << endl;
            
            cout << LONGLINE << endl;
            
            cout << "your final score is(System only calculates you wrong after revealing the correct answer, the top score is 100) : " << round(finalScore) <<  endl;
            if ( finalScore == 100 ) {
                cout << "Oh my gosh, 100% correct, you are so great bud!" << endl;
            }
            if ( finalScore >= 80 && finalScore < 100 ) {
                cout << "Good job bud, keep doing it bud. you make it 80% or more right!" << endl;
            }
            if ( finalScore >= 60 && finalScore < 80 ) {
                cout << "Not that bad bud, keep doing it bud. you make it 60% - 80% right!" << endl;
            }
            if ( finalScore < 60 ) {
                cout << "Come on bud, i know you are better than this! Just do one or two more rounds of review ok? " << endl;
            }
            
            cout << LONGLINE << endl;
            
            //review cheat sheet.
            /***************************************************************************************
             *                                                                                     *
             *                             execution part                                          *
             *                                                                                     *
             *                                                                                     *
             *                                                                                     *
             *********************t******************************************************************/
            if ( finalScore != 100 )
            {
                cout << "By the way, you still get some review cheat sheet to receive." << endl;
                cout << "Enter the file you want to store the review sheet: ";
                cin >> fileName;
                cin.ignore(1000,'\n');
                outputFile.open(fileName.c_str());
                cout << "-----------------------------------------------------------------" << endl;
                outputFile.clear();
                for (int i = 0; i < reCheck.size(); i ++)
                {
                    if ( lineSeperator > 3 )
                    {
                        cout << endl;
                        lineSeperator = 0;
                    }
                    cout << reCheck.at(i);
                    outputFile << reCheck.at(i);
                    lineSeperator++ ;
                }
                cout << endl;
                cout << "-----------------------------------------------------------------" << endl;
                
            }
            file.close();
            outputFile.close();
            cout << endl;
            cout << endl;
            cout << "Quit the new project section -- " << endl;
            cout << endl;
            cout << endl;
        }//END of first if.
        
        
        
        
        
        
        
        
        
        
        
        
        /***************************************************************************************
         *                                                                                     *
         *                             Review section                                          *
         *                                                                                     *
         *                                                                                     *
         *                                                                                     *
         ***************************************************************************************/
        if ( enter == 'R' || enter == 'r' )
        {
            cout << endl;
            cout << endl;
            cout << "Enter the review section -- " << endl;
            cout << endl;
            cout << endl;
            
            /***************************************************************************************
             *                                                                                     *
             *                             parameter declaration                                   *
             *                                                                                     *
             *                                                                                     *
             *                                                                                     *
             ***************************************************************************************/
            int score = 0;
            int lineSeperator = 0;
            int reCheckNum = 0;
            ofstream inPtfile;
            double wrongScore = 0;
            
            int vocabNum = 0;
            
            int incorrectNum = 0;
            
            string mean;
            
            string input;
            
            ifstream file;
            
            string choice;
            
            string vocab;
            
            int ans_reveal = 0;
            
            int k = 0;
            ifstream outputFile;
            
            
            int wrongNum = 0;
            if ( reCheck.size() == 0 ){
                cout << "Please start a project using P to activate first. " << endl;
                continue;}
            else{
                string choice = "unknown";
                outputFile.open(fileName.c_str());
                
                cout << "Choose a way you want to recite the vocabs:" << endl;
                cout << "                   -Enter vm for vocab to meaning" << endl;
                cout << "                   -Enter mv for meaning to vocab" << endl;
                cout << "Your choice: " ;
                cin >> choice;
                cin.ignore(100,'\n');
                /***************************************************************************************
                 *                                                                                     *
                 *                             execution part                                          *
                 *                                                                                     *
                 *                                                                                     *
                 *                                                                                     *
                 ***************************************************************************************/
                if ( choice == "mv" )
                {
                    reCheck.clear();// reuseable
                    while ( outputFile >> vocab >> mean )
                    {
                        score++ ;
                        ans_reveal = 0;
                        vocabNum++ ;
                        int wrongLimit = 0;
                        cout << "what's the vocab of " << mean << " ?: ";
                        getline(cin,input);
                        int limitTrial = 0;
                        while( input != vocab && k == 0){
                            if ( reCheckNum == 0 )
                            {
                                reCheck.push_back(vocab);
                                reCheck.push_back(" ");
                                reCheck.push_back(mean);
                                reCheck.push_back(" ");  //in case the format get mess up.
                            }
                            ans_reveal++ ;
                            if ( ans_reveal > 2 )
                            {
                                //for avoiding multiple subtracting.
                                if ( wrongLimit == 0 )
                                {
                                    wrongScore++ ;
                                    incorrectNum++ ;
                                }
                                wrongLimit++ ;
                                cout << "The right answer is: " << vocab << endl;
                            }
                            cout << "check your answer, and enter it again (control c to end the process): " ;
                            wrongNum++ ;
                            getline(cin,input);
                            
                            limitTrial = ans_reveal; // for elimiting the another ++ command.
                            
                            if (input == vocab)
                                //break the loop;
                                k = 2;
                            else
                            {
                                if ( limitTrial > 4 )
                                    k = 1; // END the program in case the user feel extreme frastrated about infinite loop of trails.
                            }
                            
                            
                            reCheckNum++ ;
                        }
                        if ( k == 2 || k == 0)
                            cout << "you are correct" << endl;
                        else
                            cout << "you have tried so many times, move to the next one!" << endl;
                        // for while loop execute again.
                        k = 0;
                        reCheckNum = 0;
                    }//END of while ( file >> vocab >> mean )
                    
                }
                /***************************************************************************************
                 *                                                                                     *
                 *                             execution part                                          *
                 *                                                                                     *
                 *                                                                                     *
                 *                                                                                     *
                 ***************************************************************************************/
                else if ( choice == "vm" )
                {
                    reCheck.clear();// reuseable
                    while ( outputFile >> mean >> vocab )
                    {
                        score++ ;
                        int wrongLimit = 0;
                        int limitTrial = 0;
                        ans_reveal = 0;
                        vocabNum++ ;
                        cout << "what's the meaning of " << mean << " ?: ";
                        getline(cin,input);
                        while( input != vocab && k == 0){
                            if ( reCheckNum == 0 )
                            {
                                reCheck.push_back(vocab);
                                reCheck.push_back(" ");
                                reCheck.push_back(mean);
                                reCheck.push_back(" ");  //in case the format get mess up.
                            }
                            ans_reveal++ ;
                            if ( ans_reveal > 2 )
                            {
                                if ( wrongLimit == 0 )
                                {
                                    wrongScore++ ;
                                    incorrectNum++ ;
                                }
                                wrongLimit++ ;
                                cout << "The right answer is: " << vocab << endl;
                            }
                            cout << "check your answer, and enter it again: (control c to end the process)" ;
                            wrongNum++ ;
                            getline(cin,input);
                            
                            limitTrial = ans_reveal; // for elimiting the another ++ command.
                            
                            if (input == vocab)
                                //break the loop;
                                k = 2;
                            else
                            {
                                if ( limitTrial > 4 )
                                    k = 1; // END the program in case the user feel extreme frastrated about infinite loop of trails.
                            }
                        }
                        if ( k == 2 || k == 0)
                            cout << "you are correct" << endl;
                        else
                            cout << "you have tried so many times, move to the next one!" << endl;
                        // for while loop execute again.
                        k = 0;
                        reCheckNum = 0;
                    }//END of while ( file >> vocab >> mean )
                }
                else
                {
                    cout << "Please Enter the right choice letters" << endl;
                    continue;
                }
            }
            /***************************************************************************************
             *                                                                                     *
             *                             execution part                                          *
             *                                                                                     *
             *                                                                                     *
             *                                                                                     *
             ***************************************************************************************/
            
            
            
            inPtfile.clear();//in case the ifstream get mess up by reading the former memory stack.
            
            
            
            //in case for empty review sheet shown.
            
            
            if ( reCheck.size() > 0 )
            {
                cout << "some review cheat sheet to receive: " << endl;
                inPtfile.open(fileName.c_str()); //this will never generate an error since the first time u run this part storeReview is 0.
                cout << "-----------------------------------------------------------------" << endl;
                for (int i = 0; i < reCheck.size(); i ++)
                {
                    if ( lineSeperator > 3 )
                    {
                        cout << endl;
                        lineSeperator = 0;
                    }
                    cout << reCheck.at(i);
                    inPtfile << reCheck.at(i);
                    lineSeperator++ ;
                }
                cout << endl;
                cout << "-----------------------------------------------------------------" << endl;
                inPtfile.close();
                outputFile.close();
            }
            
            else
                cout << "congrats you finish all of the remaining vocabs! " << endl;
            
            
            cout << endl;
            cout << endl;
            cout << "Quit the review section -- (you can choose R again to recite the ramaining vocab in the review sheet if you want.)" << endl;
            cout << endl;
            cout << endl;
            
            
        }//END of second review section.
        /***************************************************************************************
         *                                                                                     *
         *                             quitting                                                *
         *                                                                                     *
         *                                                                                     *
         *                                                                                     *
         ***************************************************************************************/
        if ( enter == 'q' || enter == 'Q' ){
            cout << "You choose to quit the program, see you later bud. " << endl;
            continues = false;
        }
        
        if ( enter != 'q' && enter != 'Q' && enter != 'r' && enter != 'R' && enter != 'p' && enter != 'P' ){
            cout << "Please enter a right choice. " << endl;
        }
    }//END of while.
    
    
    return 0;
    //normal exit.
}

