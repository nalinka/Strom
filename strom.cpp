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
   locale loc;
   string str = a;
   for (string::size_type i=0; i<str.length(); ++i){
     str[i] = tolower(str[i],loc);
     if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
       str.erase(i);
   }
   words.push_back(str);
  }
  int n = 0;
  vector<int> pocet;
  vector<string> nove;
  sort(words.begin(), words.end());
  
  
  for(int j =0; j < words.size(); j++){
   if(words[j] == words[j+1]){
    pocet[j]= pocet[j] + 1;
   } else{
    nove.push_back(words[j]);
    n++;
   } 
  }
  for(int i = 0; i < nove.size(); i++){
    printf("%s %d \n",nove[i].c_str(), pocet[i]);
  }
  
  
  fclose(file);
}
