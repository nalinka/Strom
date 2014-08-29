#include <cstdio>
#include <string>       
#include <locale>
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

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
     if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!'){
       str.erase(i);
       i--;
     }
   }
   words.push_back(str);
  }
  vector<int> pocet;
  vector<string> nove;
  pocet.resize(1);
  nove.resize(1);
  pocet[0] = 0;
  sort(words.begin(), words.end());
  
  for(int j =0; j < words.size(); j++){
   int k = j; 
   if(words[j] == words[k]){
    nove.push_back(words[k]);
    pocet.push_back(1);
    while(words[j] == words[k]){
      pocet.back()++;
      if(k == words.size() -1)
        break;
      k++;
    }
  }
 }
  for(int i = 0; i < nove.size(); i++){
   printf("%s %d \n",nove[i].c_str(), pocet[i]-1);
  }
  
  
  fclose(file);
}
