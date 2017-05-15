////
////  main.cpp
////  모스부호
////
////  Created by 김다은 on 2017. 5. 9..
////  Copyright © 2017년 김다은. All rights reserved.
////
//
//#include <iostream>
//#include <cstdlib>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main(void){
//    ifstream inStream;
//    inStream.open("/Users/Dani/Documents/ClassCpp/모스부호/모스부호/input.txt");
//    
//    if(inStream.fail()){
//        cerr<<"input file opening failed.\n";
//        exit(1);
//    }
//    
//    int T;
//    inStream >> T;
//    
//    for(int z = 0; z < T; z++){
//        string input;
//        inStream >> input;
//        
//        string alpa[26]={".-", "-...", "-.-." ,"-..", ".", "..-.",
//            "--.", "....", "..", ".---", "-.-", ".-..",
//            "--", "-.", "---", ".--.", "--.-", ".-.",
//            "...", "-", "..-", "...-", ".--", "-..-",
//            "-.--", "--.."
//        };
//        
//        string str[2001];
//        int idx = 0;
//        
//        int len = (int)input.size();
//        for(int i=0; i<len; i++){
//            char ch = input.at(i);
//            
//            if(ch == '|')
//                idx++;
//            else if(ch == '#'){
//                str[++idx] = '_';
//                idx++;
//            }
//            else
//                str[idx] += ch;
//        }
//        
//        for(int i=0; i<=idx; i++)
//            if(str[i] == "_")
//                cout << "_";
//            else
//                for(int j=0; j<26; j++)
//                    if(alpa[j] == str[i]){
//                        cout << (char)(j + 'A');
//                        break;
//                    }
//        cout << "\n";
//    }
//    inStream.close();
//}
