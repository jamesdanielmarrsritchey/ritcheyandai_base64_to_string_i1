#include <iostream>
#include <string>
#include <vector>

/*
To compile and install the program on Debian, you can follow these steps:

1. Install the g++ compiler if it's not already installed. You can do this by running the following command in your terminal:
   sudo apt-get install g++

2. Navigate to the directory containing the source code file (let's call it base64.cpp) using the cd command.

3. Compile the source code file using the g++ compiler. You can do this by running the following command in your terminal:
   g++ -o base64 base64.cpp

4. Now, you can run the program using the following command:
   ./base64 --base64_string "Your Base64 string here"

Please replace "Your Base64 string here" with the Base64 string you want to decode.
*/

const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

std::string base64_decode(const std::string &input) {
    std::string ret;
    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++) T[base64_chars[i]] = i;

    int val=0, valb=-8;
    for (auto c : input) {
        if (T[c] == -1) break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            ret.push_back(char((val>>valb)&0xFF));
            valb -= 8;
        }
    }
    return ret;
}

int main(int argc, char* argv[]) {
    std::string input;
    for(int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if(arg == "--base64_string" && i + 1 < argc) {
            input = argv[++i];
        }
    }
    std::cout << base64_decode(input);

    return 0;
}