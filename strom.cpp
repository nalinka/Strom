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
  printf("%d \n", __LINE__);
  char a[200];
  vector<string> words;
  FILE* file = fopen("in.txt", "r");
  printf("%d \n", __LINE__);
  while (true) {
   int ret = fscanf(file, "%s", a);
   if (ret == EOF)
    break;
   printf("%d \n", __LINE__);
   locale loc;
   string str = a;
   for (string::size_type i=0; i<str.length(); ++i){
     str[i] = tolower(str[i],loc);
     if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!'){
       str.erase(i);
       i--;
     }
   }
   printf("%d \n", __LINE__);
   words.push_back(str);
  }
  printf("%d \n", __LINE__);
  vector<int> pocet;
  vector<string> nove;
  pocet.resize(1);
  nove.resize(1);
  pocet[0] = 0;
  sort(words.begin(), words.end());
  printf("%d \n", __LINE__);
  
  for(int j =0; j < words.size(); j++){
   int k = j+1;
   printf("%d \n", __LINE__); 
   if(words[j] == words[k]){
    printf("%d \n", __LINE__);
    nove.push_back(words[k]);
    pocet.push_back(1);
    while(words[j] == words[k]){
      if(k == words.size() -1 )
        break;
      printf("%d \n", __LINE__);
      pocet.back()++;
      k++;
    }
  }else{
    printf("%d \n", __LINE__);
    pocet.push_back(1);
  }
 }
  for(int i = 0; i < nove.size(); i++){
   printf("%s %d \n",nove[i].c_str(), pocet[i]);
  }
  
  
  fclose(file);
}
