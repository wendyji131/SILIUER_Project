#include<iostream>
#include<string>
using namespace std;

void encryption(string& c, int a[]){

    for(int i = 0, j = 0; c[j];j++, i = (i + 1) % 8){

        c[j]+=a[i];

        if(c[j] > 122) c[j] -= 90;
    }
}
void decode(string& c,int a[]){

    for(int i = 0, j = 0; c[j];j++, i = (i + 1) % 8){

        c[j]-=a[i];

        if(c[j] < 32) c[j] += 90;
    }
}
int main(){

    int a[] = {1, 3, 7, 9, 8, 6, 4, 0};

    string s,s1;

    cout << "Enter Password��";

    cin >> s;

    s1 = s;

    encryption(s, a);

    cout << "Encrypted��" << s <<endl;

    decode(s, a);

    if(s1 == s) cout << "Origional��" << s;


    else cout << "Failed!";
}
