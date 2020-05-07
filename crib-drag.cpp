#include <iostream>
#include <string>
#include <stdlib.h> 
#include <string.h>
#include <time.h>


using namespace std;

string RandomString(int len)
{
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   int pos;
   while(newstr.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    newstr += str.substr(pos,1);
   }
   //cout<< newstr << endl;
   return newstr;
}

void string2hexString(char* input, char* output)
{
    int loop;
    int i; 
    
    i=0;
    loop=0;
    
    while(input[loop] != '\0')
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop+=1;
        i+=2;
    }
    //insert NULL at the end of the output string
    output[i++] = '\0';
}

int main(int argc, char *argv[])
{
 	char *ascii_str = argv[1]; 
 	int len = strlen(ascii_str);
    //int n = strlen(a);
    char hex_str[(len*2)+1];
    //string2hexString(key[62],hex_str);
    //cout<< hex_str << endl;
    string2hexString(ascii_str, hex_str);
    cout<< "ascii_str : " << ascii_str << endl;
    cout<< "ascii_hex : " << hex_str << endl;
    srand(time(0));
   	string s = RandomString(len);
   	cout << "random_str : " << s << endl;

    int n = s.length(); 
    char char_array[n + 1];
    //char *key_p = char_array[n];
    strcpy(char_array, s.c_str()); 

   	string2hexString(char_array, hex_str);

   	cout<<"random_hex : " << hex_str <<endl;
    
}