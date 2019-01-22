#include <iostream>
#include<string.h>

using namespace std;
void swap1(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permutations(char *str, int start, int end1)
{
    if (start == end1)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = start; i <= end1; i++)
        {
            swap1((str+start),(str+i));
            permutations(str,start+1,end1);
            swap1((str+start),(str+i));
        }
    }
}
int main(){
    char str[]="312";
   // cout<<"enter a string:-";
    //cin>>str;
    int n=strlen(str);
    permutations(str,0,n-1);
    return 0;
}
