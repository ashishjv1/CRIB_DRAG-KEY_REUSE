#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <stddef.h>
#include <stdint.h>


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

//char GenerateTen(int number)
string RandomString(int len)
{
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   int pos;
   while(newstr.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    newstr += str.substr(pos,1);
   }
   return newstr;
}

void main(int argc, char *argv[])
{
 	char *ascii_str = argv[1]; 
 	int len = strlen(ascii_str);
    //int n = strlen(a);
    char hex_str[(len*2)+1];
   	srand(time(NULL));
   	srand(time(0));
    string key = GenerateTen(len);
    printf("%c", key);
    //string2hexString(key[62],hex_str);
    printf("%s\n", hex_str);
    string2hexString(ascii_str, hex_str);
    printf("ascii_str: %s\n", ascii_str);
    printf("hex_str: %s\n", hex_str);
    
}