#include<iostream>

using namespace std;

int main()
{
    int shift;
    string txt,encrpted_txt="",decrpted_txt="";
    char total_position;

    cout << "Enter the txt" << endl;
    getline(cin,txt);

    cout << "Enter the shift position" << endl;
    cin >> shift;

    for(int i=0;i<txt.length();i++)
    {

        if(txt[i]>=65 && txt[i]<=90)
        {
            total_position=txt[i]+shift;

            if(total_position>90)
            {
                total_position=total_position-26;
            }
            encrpted_txt=encrpted_txt+total_position;

        }
        else if(txt[i]>=97 && txt[i]<=122)
        {

                total_position=txt[i]+shift;
                if(total_position>122)
                {
                    total_position=total_position-26;

                }
                encrpted_txt=encrpted_txt+total_position;
        }
        else
        {
            encrpted_txt=encrpted_txt+txt[i];
        }

    }

    cout << "encrpted_txt :";
    cout <<  encrpted_txt << endl;

    for(int i=0;i<encrpted_txt.length();i++)
    {

        if(encrpted_txt[i]>=65 && encrpted_txt[i]<=90)
        {
            total_position=encrpted_txt[i]-shift;

            if(total_position<65)
            {
                total_position=total_position+26;
            }
            decrpted_txt=decrpted_txt+total_position;

        }
        else if(encrpted_txt[i]>=97 && encrpted_txt[i]<=122)
        {

                total_position=encrpted_txt[i]-shift;
                if(total_position<97)
                {
                    total_position=total_position+26;

                }
                decrpted_txt=decrpted_txt+total_position;
        }
        else
        {
            decrpted_txt=decrpted_txt+txt[i];
        }

    }

     cout << "decrpted_txt :";
    cout <<  decrpted_txt << endl;


}
