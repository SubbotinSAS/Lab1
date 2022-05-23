#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <string>

using namespace std;

int main(void)
{
	string line;
	string preline;
	string postline;
	int n = 0;
	int nn = 0;
	ifstream in("1.txt");
	ofstream out("2.txt", ios_base::out);
	if (in.is_open() && out.is_open) {
		while(getline(in, line)){
				if(n == 0){
				  for (int i = 0; i < 2; i++) {
					line += " ";
				}
				for (int f = line.length();f>1;f--) {
				line[f] = line[f-2];
				}
				for (int ff = 0;ff<2;ff++) {
				line[ff] = ' ';
				}
				}
			for (int i = 0; i < line.length(); i++) {
			   if (n == 0 && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'r' && line[i+3] == ' ' && line[i-1] == ' ') {
				   line[i-2] = 'w';
				   line[i-1] = 'h';
				   line[i] = 'i';
				   line[i+1] = 'l';
				   line[i+2] = 'e';
				   n = 1;
			   }
			   if (n == 0 && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'r' && line[i+3] == '(' && line[i-1] == ' ') {
				   line[i-2] = 'w';
				   line[i-1] = 'h';
				   line[i] = 'i';
				   line[i+1] = 'l';
				   line[i+2] = 'e';
				   n = 1;
			   }
			   if (n == 0 && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'r' && line[i+3] == ' ' && line[i-1] == '	') {
				   line[i-2] = 'w';
				   line[i-1] = 'h';
				   line[i] = 'i';
				   line[i+1] = 'l';
				   line[i+2] = 'e';
				   n = 1;
			   }
			   if (n == 0 && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'r' && line[i+3] == '(' && line[i-1] == '	') {
				   line[i-2] = 'w';
				   line[i-1] = 'h';
				   line[i] = 'i';
				   line[i+1] = 'l';
				   line[i+2] = 'e';
				   n = 1;
			   }
			   if (line[i] == '(' && n == 1) {
				   n = 2;
			   }
			   if (n == 2) {
                if (line[i] != '('){
				   int r = i;
				   while(line[r] != ';'){
				   preline += line[i];
				   //line[i] = ' ';
				   line.erase(r,1);
				   }
			   }
					if (line[i] == ';') {
					   n = 3;
					   //line[i] = ' ';
					   line.erase(i,1);
					   preline += ';';
					}
			   }
			   if (n == 3) {
			   n = 4;
			   out<<preline<<endl;
			   preline = ' ';
			   preline.erase();
			   }
			   if (n == 4 && line[i] == ';') {
						//line[i] = ' ';
					 line.erase(i,1);
					 n = 5;
			   }

			   if (n == 5) {
               	  if (line[i] != ')') {
				  int r = i;
				  while(line[r] != ')'){
				   postline += line[r];
				   //line[i] = ' ';
				   line.erase(r,1);
				  }
				  }
					 if (line[i] == ')') {
					   n = 6;
					   postline += ';';
					 }
			   }
			   if (n == 6 && line[i] == '{') {
				   n = 7;
			   }
			   if (n == 6 && line[i] == ';') {
					int ttt = i;
					int tt = postline.length();
					for (int t = 0; t < tt; t++) {
					line += " ";
					}
					for (int r = line.length(); r > i+tt; r--) {
						  line[r] = line[r-tt];
					}
					for (int rr = ttt; rr < i+tt; rr++) {
						line[rr] = postline[rr-ttt];
					}
					n = 0;
					postline = ' ';
					postline.erase();
			   }
			   if (n == 7 && line[i] == '}') {
					int ttt = i;
					int tt = postline.length();
					for (int t = 0; t < tt; t++) {
					line += " ";
					}
					for (int r = line.length(); r > i+tt-1; r--) {
						  line[r] = line[r-tt];
					}
					for (int rr = ttt; rr < i+tt; rr++) {
						line[rr] = postline[rr-ttt];
					}
					n = 0;
					postline = ' ';
					postline.erase();
			   }
			   if (n == 6) {
			   if (nn == 0 && line[i] != ' ' && line[i] != '	' && line[i] != '}' && line[i] != '{' && line[i] != ';' && line[i] != ')'){
				   line[i-1] = '{';
				   line += "}";
				   n = 7;
				   nn = 1;
			   }
			   }
			}
			nn = 0;
			out<<line<<endl;
			cout<<line<<endl;
		}
	}
	else
	cout<<"Error!"<<endl;

	Sleep(100000);
	in.close();
	//out.close();
	return 0;
}
