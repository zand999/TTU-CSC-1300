

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main(){
  string input;
  string abriviations[10] = {"BFF","IDK","JK","TMI","TTYL","YMMD","W8","QT","AYTMTB","WTF"};
  string replace[10] = {"best friend forever","I don't know","just joking","too much information","talk to you later","you made my day","wait","cutie","and you're telling me this because","what the frick"};

  cout << "Enter text: ";
  getline(cin, input);
  //cout << input.find(abriviations[0])<<endl;
  cout << endl << "You entered: " << input << endl;

  for(int i = 0; i < 10 ; i++){
    if(input.find(abriviations[i]) != string::npos){
      input.replace(input.find(abriviations[i]),abriviations[i].size(),replace[i]);
    }

  }
  cout << "\nExpanded: " << input <<endl;
  return 0;

}
