#include <cstdio>
#include <string>       
#include <locale>
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

void PrintVectorStr(vector<string> list) {
  for(int i = 0; i < list.size(); i++){
    printf("%s \n",list[i].c_str());
  }
}

string normalize(string str){
  locale loc;
  for (string::size_type i=0; i<str.length(); ++i){
    str[i] = tolower(str[i],loc);
    if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!'){
      str.erase(i);
      i--;
    }
  }
  return str;
}

int main() {
  char a[20000];
  vector<string> words;
  FILE* file = fopen("in.txt", "r");
  //vlozit slova a normalizovat
  while (true) {
   int ret = fscanf(file, "%s", a);
   if (ret == EOF)
    break;
   string str = a;
   str = normalize(str); 
   words.push_back(str);
  }
  //usporiadat a spocitat
  vector<int> pocet;
  vector<string> nove;
  sort(words.begin(), words.end());
  int k = 0;
  for(int j =0; j < words.size(); j++){
   if(j< k)
    continue;
   k = j; 
   if(words[j] == words[k]){
    nove.push_back(words[k]);
    pocet.push_back(0);
    while(words[j] == words[k]){
      pocet.back()++;
      if(k == words.size() -1)
        break;
      k++;
    }
  }
 }
 //vypisat
 PrintVectorStr(nove);
 
 
 char in[200];
 scanf("%s", in);
 string in_str = in;
 in_str = normalize(in_str);
 bool n = false;
 vector<string> slovo;
 int max = 0;
 for(int i = 0; i < nove.size(); i++){
   for (int j=0; j<in_str.length(); ++j){
     n = false;
     if(nove[i][j]==in_str[j]){
       continue; 
     }else{
       n = true;
       break;
     }
   }
   if(n == true){
     continue;
   }
   if(pocet[i] >= max){
     max = pocet[i];
     slovo.push_back(nove[i]);
   } 
 }
 printf(" %d \n", max); 
 PrintVectorStr(slovo); 
 fclose(file);
}
