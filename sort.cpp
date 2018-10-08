#include <iostream>
#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of sort.  Supported options:\n\n"
"   -r,--reverse        Sort descending.\n"
"   -f,--ignore-case    Ignore case.\n"
"   -u,--unique         Don't output duplicate lines.\n"
"   --help              Show this message and exit.\n";


/* NOTE: set<string,igncaseComp> S; would declare a set S which
 * does its sorting in a case-insensitive way! */


vector<string> reverseoutput(vector<string>& input);
void routput(vector<string>& input);
vector<string>noduplicates(vector<string>& vlinein);
vector<string> IgnoreCaseSort(vector<string>& vlinein);
void printvector(vector<string>& vlinein);

//AnthiP FALL2017

struct Ignore {
	bool operator()(const string& a, const string& b)
	{
		int siz=min(a.length(), b.length());

	for (int i = 0; i<siz; i++)
	{

		if (toupper((a[i]) < toupper(b[i])))
			return true;
		else if (toupper(a[i]) > toupper(b[i]))
			 return false;

  }
	return true;
}
};


int main(int argc, char *argv[]) {
	// define long options


	static int descending=0, ignorecase=0, unique=0;
	static struct option long_opts[] = {
		{"reverse",       no_argument,   0, 'r'},
		{"ignore-case",   no_argument,   0, 'f'},
		{"unique",        no_argument,   0, 'u'},
		{"help",          no_argument,   0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "rfuh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'r':
			{descending = 1;
				break;
			}
			case 'f':
			{
				ignorecase = 1;
   			break;
			}
			case 'u':
			{
				unique = 1;
				break;
			}
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}}

	string input;
	vector<string> vlinein;

	while (getline(cin, input))
	{
		if (input.empty() == false)
// saving each line or word passed as a new element in the vector
			vlinein.push_back(input);
	}
	    //sorting ascending order as per default instructions
			sort(vlinein.begin(), vlinein.end());

	//if no flags are used print input in default sort (ascending)
	if ((descending==0) && (unique==0) && (ignorecase==0))
		printvector(vlinein);

	else
	{

	if ((descending==1)&&(unique==0) && (ignorecase==0))
	{
		//reverseoutput(vlinein);
		vector<string> v;
		v=reverseoutput(vlinein);
		printvector(v);

	}
	if((ignorecase==1)&&(unique==0)&&(descending==0))
	{
		//IgnoreCaseSort(vlinein);
		vector <string> v1;
		v1=IgnoreCaseSort(vlinein);
		printvector(v1);
	}
	if((unique==1)&&(descending==0)&&(ignorecase==0))
	{
		//noduplicates(vlinein);
		vector <string> v2;
		v2=noduplicates(vlinein);
		printvector(v2);
	}

	if ((descending==1)&& (unique==1)&&(ignorecase==0))
	{
			vector<string>ud;
		  ud=noduplicates(vlinein);
		  routput(ud);

	}
	if ((descending==1)&&(unique==1)&&(ignorecase==1))
	{  vector<string> u_d;
		 vector<string> udi;
		 u_d=IgnoreCaseSort(vlinein);
		 udi=noduplicates(u_d);
		 printvector(udi);

	}

	if ((descending==1) && (ignorecase==1) && (unique==0))
	{
		vector<string>di;
		di=IgnoreCaseSort(vlinein);
		routput(di);
	}

	if ((descending==0) && (ignorecase==1) && (unique==1))
	{
		vector<string> iu;
		vector<string> iu2;
		iu=IgnoreCaseSort(vlinein);
		iu2=noduplicates(iu);
		printvector(iu2);

	}

		}

}

void routput(vector<string>& input)
{
	//vector is already sorted in ascending order in main();
	//displaying output in reversed order
	for (int i=input.size()-1; i >=0; --i)
	{
		cout << input[i]<< endl;
	}

}

/*void routput(vector<string>& input)
{
	for  (int i=input.size()-1; i>=0; i--)
	    cout<<input[i]<<endl;
}
*/
vector<string> reverseoutput(vector<string>& input)
{


		vector<string> temp;
		for (int i=input.size()-1; i>=0; i--)
	{
	    temp.push_back(input[i]);
	}
	//printvector(temp);
	return temp;

}

vector<string> noduplicates(vector<string>& vlinein)
{
//removing the consecutive duplicates from the sorted vector and resizing the vector to display only the unique elements
	vector<string> s;
for (int i=0; i<vlinein.size(); i++)
{
	s.push_back(vlinein[i]);
}
	s.resize(distance(s.begin(), unique(s.begin(),s.end())));

	// for (int i=0; i<=vlinein.size()-1; i++)
	 //{
		// cout<< vlinein[i];
		// cout<<endl;
 //printvector(s);
 return s;
	 }



vector<string> IgnoreCaseSort(vector<string>& vlinein)
{
	Ignore cmp;
	vector<string> temp;
	for (int i=0; i<vlinein.size(); i++)
	 {
		 temp.push_back(vlinein[i]);
	 }
  sort(temp.begin(),temp.end(),cmp);
	 //printvector(temp);
	 return temp;
 }
//utiliizing the c++ sort that allows for the third parameter --> passing the input string into the compare case function



//function to print the output of a vector

void printvector(vector<string>& vlinein)
{
	for (int i=0; i<vlinein.size(); i++)
	    cout<< vlinein[i]<<endl;
}
