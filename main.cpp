#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char hexa[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
int initial_permutation[64] = { 58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17, 9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7 };
int ExpansionDbox[48] = { 32, 1, 2, 3, 4, 5, 4, 5,6, 7, 8, 9, 8, 9, 10, 11,12, 13, 12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21,22, 23, 24, 25, 24, 25, 26, 27,28, 29, 28, 29, 30, 31, 32, 1 };
int S_box_Table[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                            0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                            4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                            15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                    { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                            3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                            0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                            13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                    { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                            13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                            13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                            1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                    { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                            13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                            10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                            3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                    { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                            14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                            4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                            11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                    { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                            10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                            9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                            4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                    { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                            13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                            1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                            6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                    { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                            1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                            7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                            2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

int straight_per[32] = { 16, 7, 20, 21,29, 12, 28, 17,1, 15, 23, 26,5, 18, 31, 10,2, 8, 24, 14,32, 27, 3, 9,19, 13, 30, 6,22, 11, 4, 25 };
int final_per[64] = { 40, 8, 48, 16, 56, 24, 64, 32,39, 7, 47, 15, 55, 23, 63, 31,38, 6, 46, 14, 54, 22, 62, 30,37, 5, 45, 13, 53, 21, 61, 29,36, 4, 44, 12, 52, 20, 60, 28,35, 3, 43, 11, 51, 19, 59, 27,34, 2, 42, 10, 50, 18, 58, 26,33, 1, 41, 9, 49, 17, 57, 25 };
int keypermutation[56] = { 57, 49, 41, 33, 25, 17, 9,1, 58, 50, 42, 34, 26, 18,10, 2, 59, 51, 43, 35, 27,19, 11, 3, 60, 52, 44, 36,63, 55, 47, 39, 31, 23, 15,7, 62, 54, 46, 38, 30, 22,14, 6, 61, 53, 45, 37, 29,21, 13, 5, 28, 20, 12, 4 };
int shiftleft[16] = { 1, 1, 2, 2,2, 2, 2, 2,1, 2, 2, 2,2, 2, 2, 1 };
int key_comperession[48] = { 14, 17, 11, 24, 1, 5,3, 28, 15, 6, 21, 10,23, 19, 12, 4, 26, 8,16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55,30, 40, 51, 45, 33, 48,44, 49, 39, 56, 34, 53,46, 42, 50, 36, 29, 32 };




string binary_to_hexa(string binary)
{
    unordered_map<string, string> binhex;
    binhex["0000"] = "0";
    binhex["0001"] = "1";
    binhex["0010"] = "2";
    binhex["0011"] = "3";
    binhex["0100"] = "4";
    binhex["0101"] = "5";
    binhex["0110"] = "6";
    binhex["0111"] = "7";
    binhex["1000"] = "8";
    binhex["1001"] = "9";
    binhex["1010"] = "A";
    binhex["1011"] = "B";
    binhex["1100"] = "C";
    binhex["1101"] = "D";
    binhex["1110"] = "E";
    binhex["1111"] = "F";
    string hexa = "";
    for (int i = 0; i < binary.length(); i += 4) {
        string ch = "";
        ch += binary[i];
        ch += binary[i + 1];
        ch += binary[i + 2];
        ch += binary[i + 3];
        hexa += binhex[ch];
    }
    return hexa;
}

string xor_num(char num1,char num2)
{
    if (num1==num2)
    {
        return "0";
    }
    else{
        return  "1";
    }

}
string xor_calc(string num1,string num2){
    string output;
    for (int i =0 ; i<num1.length();i++)
    {
        output+= xor_num(num1[i],num2[i]);
    }
    return output;

}


string hexa_to_binary(string hexa)
{
    unordered_map<char, string> hexbin;
    hexbin['0'] = "0000";
    hexbin['1'] = "0001";
    hexbin['2'] = "0010";
    hexbin['3'] = "0011";
    hexbin['4'] = "0100";
    hexbin['5'] = "0101";
    hexbin['6'] = "0110";
    hexbin['7'] = "0111";
    hexbin['8'] = "1000";
    hexbin['9'] = "1001";
    hexbin['A'] = "1010";
    hexbin['B'] = "1011";
    hexbin['C'] = "1100";
    hexbin['D'] = "1101";
    hexbin['E'] = "1110";
    hexbin['F'] = "1111";
    string binary = "";
    for (int i = 0; i < hexa.size(); i++) {
        binary += hexbin[hexa[i]];
    }
    return binary;
}

string permute(string s, int* perm, int size)
{
    string out = "";
    for (int i = 0; i < size; i++) {
        int index =perm[i] - 1;
        out += s[perm[i] - 1];
    }
    return out;
}

string leftshift(string k, int shifts)
{
    string s = "";
    for (int i = 0; i < shifts; i++) {
        for (int j = 1; j < 28; j++) {
            s += k[j];
        }
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}

vector<string> key_process(string keyy){

    string key = hexa_to_binary(keyy);
    key = permute(key, keypermutation, 56);
    string left_key = key.substr(0, 28);
    string right_key = key.substr(28, 28);
    vector<string> k;

    for (int i = 0; i < 16; i++) {
        left_key= leftshift(left_key,shiftleft[i]);
        right_key= leftshift(right_key,shiftleft[i]);
        string h =left_key+right_key;
        k.push_back(permute(h,key_comperession,48));
    }
    return k;



}


string encrypt(string ptext, vector<string>key)
{


    string plain_text = hexa_to_binary(ptext);
    plain_text=permute(plain_text,initial_permutation,64);
    string l = plain_text.substr(0, 32);
    string r = plain_text.substr(32, 32);

    for (int i = 0; i < 16; i++) {

        string expanded_r= permute(r,ExpansionDbox,48);
        string r_xor_k = xor_calc(key[i],expanded_r);
        string s_boxout= "";
        for (int i = 0; i < 8; i++) {
            int row = 2 * int(r_xor_k[i * 6] - '0') + int(r_xor_k[i * 6 + 5] - '0');
            int col = 8 * int(r_xor_k[i * 6 + 1] - '0') + 4 * int(r_xor_k[i * 6 + 2] - '0') + 2 * int(r_xor_k[i * 6 + 3] - '0') + int(r_xor_k[i * 6 + 4] - '0');
            int val = S_box_Table[i][row][col];
            s_boxout+= char(val / 8 + '0');
            val = val % 8;
            s_boxout+= char(val / 4 + '0');
            val = val % 4;
            s_boxout+= char(val / 2 + '0');
            val = val % 2;
            s_boxout+= char(val + '0');
        }

        string permuate_sbox=permute(s_boxout, straight_per, 32);
        r_xor_k= xor_calc(permuate_sbox,l);
        l=r_xor_k;
        if (i != 15) {
            string g=l;
            l=r;
            r=g;
        }

    }
    string lr=l+r;
    string ciphertext= permute(lr,final_per,64);
    return binary_to_hexa(ciphertext);

}

int main() {

    string type,c, key;

    cin>>type>>c>>key;
    vector<string>keyyy =key_process(key);
    if (type=="encrypt")
    {
        string text = encrypt(c, keyyy);
        cout<<"cipher: "<<text;
    }
    if (type=="decrypt")
    {
        reverse(keyyy.begin(), keyyy.end());
        string text = encrypt(c, keyyy);
        cout<<"plain: "<<text;
    }
}


