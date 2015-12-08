//g++ xml.cpp -lboost_system -lboost_filesystem -lboost_program_options

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

struct tag_separator{
  void reset(){}
  template<typename Iterator,typename Token>
  bool operator()(Iterator&i, Iterator end, Token& tok){
    tok =Token();
    if(i==end){
	return false;
      }
    if(*i=='<'){
      for(;i!=end && *i!='>';i++){
	tok+=*i;
      }
      if(i==end){
	return false;
      }
      tok +=*i++;
      return true;
    }else{
      for(;i!=end && *i!='<';i++){
	tok+=*i;
      }
      return true;
    }
  }
};

int main(){
  // cin.unsetf(ios_base::skipws);
  //string str((istream_iterator<char>(cin)), istream_iterator<char>());
  fstream file;
  file.open("status.xml",ios_base::in);
  string str;
  string temp;
  if(file.is_open()){
    do{
	getline(file,temp);
   	 str+=temp;
    	//cout<<"data"<<str<<endl;
     }while(! file.eof());
  }else{
    cout<<"file error"<<endl;
  }

  tokenizer<tag_separator> tokens(str);
  typedef tokenizer<tag_separator>::iterator Iter;
  for(Iter it=tokens.begin(); it!=tokens.end(); ++it){
	//if(*it=="<function>"){
		//cout<<"Hello: "<<*it<<endl;
	//}else{
    		cout<<"TOKEN: "<<*it<<endl;
        //}
  }
  return 0;
}
