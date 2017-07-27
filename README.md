# WeekOneProblemMsft

/*Questions: should we distinguish is the input is an int or char? are the only char allowed letters?
a solution might be to take the user input but i'm not sure how to distinguish bewteen the number colon and string
 */
//main.cpp

#include <iostream>
#include<string.h>
using namespace std;

int main() {
    //ask user for an int between -1billion and 1billion. else if it is a char.
    string input;
    
    //provide input string number followed by semicolon folowed by text
    cout<<"Enter an integer followed by a : and an integer or character(s) space is acceptable. For example: 1:Jada" << endl;
    
    //take input string
    getline(cin,input);
    
    //convert input string into const char so we can use strtok e.i. tokenizer function
    const char *str = input.c_str();
    
    //cout << str << endl;
    //remove constness from input text as strtok accpet argument char * only not const char*
    char *str1 = const_cast <char *>(str);
    
    int shiftNum = 0; // to store number of shift to perform
    char *text = nullptr; // to store text on which shift will perfrom
    int i=1; // use index to take take care two part of input string
    
    //strtok tokenizer input string by ":"
    char *pch = strtok (str1,":");
    while (pch != NULL)
    {
        //cout << pch << endl;
        if(i==1)
        {
            shiftNum = atoi(pch); //atoi function used to convert char* into integer
            //cout << "shiftNum: " << shiftNum << endl;
        }
        if(i==2)
        {
            text = pch; // in second we take text part
            //cout << "text: " << text << endl;
        }
        pch = strtok (NULL, ":");
        i++;
    }
    
    //Now incerse char in input one by one till number of shift remains
    while(shiftNum !=0)
    {
        //traverse through input text
        for(int i=0;i<strlen(text);i++)
        {
            //if current char is a small alphabet
            if(text[i] >='a' && text[i] <='z')
            {
                //if curr char is z then it becomes a
                if(text[i] == 'z')
                    text[i] = 'a';
                //else simply increase by 1 and replace with next char value
                else
                    text[i] += 1;
            }
            //if current char is a capital alphabet
            else if(text[i] >='A' && text[i] <='Z')
            {
                //if curr char is Z then it becomes A
                if(text[i] == 'Z')
                    text[i] = 'A';
                //else simply increase by 1 and replace with next char value
                else
                    text[i] += 1;
            }
            //if current char is a number
            else if(text[i] >='0' && text[i] <='9')
            {
                //if curr char is 9 then it becomes 0
                if(text[i] == '9')
                    text[i] = '0';
                //else simply increase by 1 and replace with next char value
                else
                    text[i] += 1;
            }
        }
        shiftNum--;
    }
    
    cout << text << endl;
    
    return 0;
}
