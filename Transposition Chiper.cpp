#include <bits/stdc++.h>
using namespace std;

string encrypt(string key, char mat[][10]) {
  int rows = sizeof(mat) / sizeof(mat[0]);
  int cols = sizeof(mat[0]) / sizeof(mat[0][0]);

  string result = "";
  for(int i=0; i < cols; i++) {
    int selCol = key[i]-'0'-1;
    for(int j = 0; j < 5; j++) {
      if(mat[j][selCol]==0) continue;
      result+=mat[j][selCol];
    }
  }

  return result;
}

void decrypt(string key, string cipher) {
  int rows = 5;
  int cols = 10;
  char mat[5][10];

  int i=0, k=0, m=0;

  while(k < cipher.length()) {
    int selCol = key[m]-'0'-1;
    cout<<selCol;
    mat[i][selCol] = cipher[k];
    k++;
    i++;
    if(i==rows) {
      i=0;
      m++;
    }
  }

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

int main()
{
    string message = "DEPARTMENTOFCOMPUTERSCIENCEANDENGINNERING";
    string key = "12345";
    // char mat[ceil(message.length()/3)][key.length()]; // mat[3][3]
    char mat[5][10];

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

    cout<<"Matrix: \n";
    for(int i=0; i < 5; i++) {
      for(int j=0; j < 10; j++) {

        if(mat[i][j]>='A' && mat[i][j]<='Z')
        {
            cout<<mat[i][j]<<'\t';
        }

      }
      cout<<endl;
    }

    cout<<"Cipher: ";
    string cipher = encrypt(key, mat);
    cout<<cipher;

    decrypt(key, cipher);

    return 0;
}
