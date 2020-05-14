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


string HexToBin(string hexdec) 
{ 
    long int i = 0; 
  	string tmp;
    while (hexdec[i]) { 
  
        switch (hexdec[i]) { 
        case '0': 
            tmp += "0000"; 
            break; 
        case '1': 
            tmp += "0001"; 
            break; 
        case '2': 
            tmp += "0010"; 
            break; 
        case '3': 
            tmp += "0011"; 
            break; 
        case '4': 
            tmp += "0100"; 
            break; 
        case '5': 
            tmp += "0101"; 
            break; 
        case '6': 
            tmp += "0110"; 
            break; 
        case '7': 
            tmp += "0111"; 
            break; 
        case '8': 
            tmp += "1000"; 
            break; 
        case '9': 
            tmp += "1001"; 
            break; 
        case 'A': 
        case 'a': 
            tmp += "1010"; 
            break; 
        case 'B': 
        case 'b': 
            tmp += "1011"; 
            break; 
        case 'C': 
        case 'c': 
            tmp += "1100"; 
            break; 
        case 'D': 
        case 'd': 
            tmp += "1101"; 
            break; 
        case 'E': 
        case 'e': 
            tmp += "1110"; 
            break; 
        case 'F': 
        case 'f': 
            tmp += "1111"; 
            break; 
        default: 
            cout << "\nInvalid hexadecimal digit ";
            
            cout <<tmp[i]; 
        } 
        i++; 
    } 
return tmp;
} 

void xorstring(string input_string, string random_string)
{
	//char test2 = random_string;
	int n = input_string.length();
	string binary1 = HexToBin(input_string);
	string binary2 = HexToBin(random_string);
	int len = binary2.size();
	//cout << "length is"<<len;
	char final_key[len];              //need to check size
	cout<<"Binary-String: " << binary1;
	cout<< endl;
	cout<<"Binary-Random: " << binary2;
	cout << endl;
	for(int i=0; i < len; i++)
	{
		final_key[i] = ((binary1[i] - '0') ^ (binary2[i] - '0')) + '0';
	//	final_key[i] = (binary1[i] ^ binary2[i]); 
	//	cout << final_key ;
	}
	cout<<"Encrypted data:"<< final_key<<endl;
	
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
    char hex_str_random[(n*2)+1];
    char char_array[n + 1];
    //char *key_p = char_array[n];
    strcpy(char_array, s.c_str()); 

   	string2hexString(char_array, hex_str_random);

   	cout<<"random_hex : " << hex_str_random <<endl;
    
    xorstring(hex_str, hex_str_random);

}

