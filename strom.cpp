#include <cstdio>
#include <string>       
#include <locale>
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int main() {
  char a[20000];
  vector<string> words;
  FILE* file = fopen("in.txt", "r");
  //vlozit slova a normalizovat
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
 for(int i = 0; i < nove.size(); i++){
  printf("%s %d \n",nove[i].c_str(), pocet[i]);
 }
 char in[200];
 scanf("%s", in);
 string in_str = in;
 bool n = false;
 string slovo;
 int max = 0;
 for(int i = 0; i < nove.size(); i++){
   printf(" %d \n", __LINE__);
   for (int j=0; j<in_str.length(); ++j){
     n = false;
     printf(" %d \n", __LINE__);
     if(nove[i][j]==in_str[j]){
       printf(" %d \n", __LINE__);
       printf("%s %d \n", nove[i].c_str(), max);
       continue; 
     }else{
       printf(" %d \n", __LINE__);
       n = true;
       break;
     }
   }
   if(n == true){
     printf(" %d \n", __LINE__);
     continue;
   }
   printf(" %d \n", __LINE__);
   printf("%s %d \n", nove[i].c_str(), max);
   if(pocet[i] > max){
     printf(" %d \n", __LINE__);
     max = pocet[i];
     slovo = nove[i];
   } 
 }
 printf("%s %d \n", slovo.c_str(), max); 
  
 fclose(file);
}
