// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.
#include <iostream>

using namespace std;
/*
O(n)
s1 in place 
Cant use additional memory O(n)
Valid input
*/
void remove_substr(char* s1, const char* s2) {
    // TODO: finish me
   // int n1 = strlen(s1);
   // int n2 = strlen(s2);
    int start= 0, end=0, k=0;
    int start2 =0;
    int end2 = 0;
    int fin = 0;
    int lens2 = 0;
    for (start=0; s1[start] != '\0'; ++start) {
        for (end = start; s1[end] == s2[k]; ++k, ++end) {
			k = 0;
            start2 = start;

       //     cout << "start " << start << endl;
            cout << "k " << k << endl;
            if (s2[k] == '\0') {
                fin = 1;
                break;
            }
        }
        cout << "k 2: " << k << endl;
        if (fin) {
            cout << "k " << k << endl;
			cout << "lens2: " << lens2 << endl;
            lens2 = k;
            break;
        }
    }
	cout << "lens2: " << lens2 << endl;
   // cout << "start after " << start2 << endl;
  //  cout << "k " << k << endl;
    if (k > 0) {// && s2[k] == '\0') {
      end2 = start +lens2;
      cout << "end2" << end2 << endl;

      while (s1[start2] != '\0' && s2[end2] != '\0') {
        s1[start2++] = s1[end2++];
      }
      s1[start2] = '\0';
    }
    /*
    char str[] = "aaabc";
                    ^ ^ we need to include the '\0' co
    remove_substr(str, "ab"); 
    */
   
    // here we have the starting index and the end index in s1
    
    
}

int main(int argc, char** argv) {
    char str[] = "aaabc";
    remove_substr(str, "ab");   // After this, str will be "aac"
	cout << str << endl;
 /*   remove_substr(str, "aaa");  // After this, str will not change
	cout << str << endl;
    remove_substr(str, "a");  // After this, str will be an empty string
	cout << str << endl;*/
    return 0;
}



