// status:-Not completed
#include <iostream>
#include <string.h>
using namespace std;
void swape(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
void permutations(char *str, int s, int e)
{
    if (s == e)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = s; i <= e; i++)
        {
            swape((str + s), (str+i));
            permutations(str,s+1,e);
            swape((str + s), (str+i));
        }
    }
}
int main(){
    char str[1000];
    cin>>str;
    int n=strlen(str);
    permutations(str,0,n-1);
    return 0;
}
