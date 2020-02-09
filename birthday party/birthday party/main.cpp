//
//  main.cpp
//  birthday party
//
//  Created by YunBum Han on 2020/02/09.
//  Copyright © 2020 YunBum Han. All rights reserved.
//
//#include <windows.h>
#include <iostream>
#include <locale>

using namespace std;

int main(){
    wcout.imbue( locale("korean") );
    
    wchar_t CompleteCode = L'개';
    wchar_t UniValue = CompleteCode - 0xAC00;

    wchar_t Jong = UniValue % 28;
    wchar_t Jung = ( ( UniValue - Jong ) / 28 ) % 21;
    wchar_t Cho = ( ( UniValue - Jong ) / 28 ) / 21;

    cout << "초성 : " << Cho << "\t" << "중성 : " << Jung << "\t" << "종성 : " << Jong << endl;
}

//https://cfdf.tistory.com/45
