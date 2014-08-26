#include <cstdio>
#include <string>       
#include <locale>
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

void PrintVector(const vector<string> list) {
  for(int i = 0; i < list.size(); i++){
    printf("%s \n",list[i].c_str());
  }
}

int main() {

char a[200];
vector<string> words;
FILE* file = fopen("in.txt", "r");
while (true) {
 int ret = fscanf(file, "%s", a);
 if (ret == EOF)
  break;
 std::locale loc;
 std::string str = a;
 for (std::string::size_type i=0; i<str.length(); ++i){
   str[i] = std::tolower(str[i],loc);
   if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
     str.erase(i);
 }
 words.push_back(str);
}
PrintVector(words);
fclose(file);
}
