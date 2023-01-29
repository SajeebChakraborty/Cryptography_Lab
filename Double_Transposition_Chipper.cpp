#include <bits/stdc++.h>
using namespace std;

    char mat[5][10];
    char mat2[5][10];

string encrypt(string key, char mat[][10]) {
  int rows = sizeof(mat) / sizeof(mat[0]);
  int cols = sizeof(mat[0]) / sizeof(mat[0][0]);

  string result = "";
  int k=0,i=0,j=0;
  while(k < 50) {

    //result=result+mat[i][j];
    if(mat[i][j]>='A' && mat[i][j]<='Z')
    {
        result=result+mat[i][j];
    }
    k++;
    i++;
    if(i==5) {
      i=0;
      j++;
    }
  }

  return result;
}

string double_encrypt(string key, char mat2[][10]) {
  int rows = sizeof(mat) / sizeof(mat2[0]);
  int cols = sizeof(mat[0]) / sizeof(mat2[0][0]);

  string result = "";
  int k=0,i=0,j=0;
  while(k < 50) {

    //result=result+mat[i][j];
    if(mat2[i][j]>='A' && mat2[i][j]<='Z')
    {
        result=result+mat2[i][j];
    }
    k++;
    i++;
    if(i==5) {
      i=0;
      j++;
    }
  }

  return result;
}

void decrypt(string key, string cipher) {
  int rows = 5;
  int cols = 10;

  int i=0, k=0, m=0;

  int j=0;
  cout<<"\nPlain Text: ";


  for(int i=0; i < 5; i++) {
    for(int j=0; j < 10; j++) {
      // if(mat[i][j]==0) continue;
      if(mat[i][j]>='A' && mat[i][j]<='Z')
      {
        cout<<mat[i][j];
      }
    }
  }
}

string double_decrypt(string key, string cipher) {
  int rows = 5;
  int cols = 10;

  int i=0, k=0, m=0;

  int j=0;
  cout<<"\nPlain Text: ";

  string result2 = "";


  for(int i=0; i < 5; i++) {
    for(int j=0; j < 10; j++) {
      // if(mat[i][j]==0) continue;
      if(mat[i][j]>='A' && mat[i][j]<='Z')
      {
        result2=result2+mat[i][j];
      }
    }
  }

  return result2;

}

int main()
{
    string message = "DEPARTMENTOFCOMPUTERSCIENCEANDENGINNERING";
    string key = "12345";
    // char mat[ceil(message.length()/3)][key.length()]; // mat[3][3]


    cout<<"Message: "<<message<<endl;
    cout<<"Key: "<<key<<endl;

    int i=0, j=0, k=0;
    while(k < message.length()) {

      mat[i][j] = message[k];
      k++;
      j++;
      if(j==10) {
        j=0;
        i++;
      }
    }

    //cout<<"Matrix: \n";
    for(int i=0; i < 5; i++) {
      for(int j=0; j < 10; j++) {

        if(mat[i][j]>='A' && mat[i][j]<='Z')
        {
            // cout<<mat[i][j]<<'\t';
        }

      }
      // cout<<endl;
    }

    // cout<<"Cipher: ";
    string cipher = encrypt(key, mat);

    i=0; j=0; k=0;
    while(k < cipher.length()) {

      mat2[i][j] = cipher[k];
      k++;
      j++;
      if(j==10) {
        j=0;
        i++;
      }
    }

    cout<<"Matrix: \n";
    for(int i=0; i < 5; i++) {
      for(int j=0; j < 10; j++) {

        if(mat2[i][j]>='A' && mat2[i][j]<='Z')
        {
            cout<<mat2[i][j]<<'\t';
        }

      }
      cout<<endl;
    }
    cout<<"Cipher: ";
    string double_cipher = double_encrypt(key, mat2);
    cout<< double_cipher;

    string double_decrpt=double_decrypt(key, double_cipher);

    cout << double_decrpt;


    return 0;
}
