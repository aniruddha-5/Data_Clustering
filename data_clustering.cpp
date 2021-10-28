#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define frr(i,a,n) for(ll i=a;i<n;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)

#define MOD 1000000007
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define F first
#define S second
#define vi vector<ll>
#define pii pair<ll,ll>


int main()
{
	string line;
  	ifstream myfile ("log file.txt");
  	vector<int> machine;
  	unordered_map<int,string> arrival;
  	unordered_map<int,string> exit;
  	unordered_map<int,int> alloted;
  	unordered_map<int,int> status;
  	if (myfile.is_open())
  	{
  		int pos=0;
    	while ( getline (myfile,line) )
    	{
      		for(int i=0;i<line.length();i++)
      		{
      			if(line[i]==' ')
      			{
      				pos=i;
      				break;
				}
			}
			string v = line.substr(0,12);
			if(v=="initializing")
			{
				string t=line.substr(line.length()-4,4);
				int x = stoi(t);
				machine.pb(x);
			}
			string r = line.substr(pos+1,7);
			if(r=="request")
			{
				string t=line.substr(line.length()-4,4);
				int x = stoi(t);
				string s=line.substr(pos+9,9);
				if(s=="processed")
				{
					string z=line.substr(pos+32,3);
					int y = stoi(z);
					alloted[x]=y;
				}
				else
				{
					string z=line.substr(pos+16,5);
					arrival[x]=z;
				}
			}
			if(r=="success")
			{
				string t=line.substr(line.length()-4,4);
				int x = stoi(t);
				string z=line.substr(pos+16,5);
				exit[x]=z;
				status[x]=1;
			}
			if(r=="failure")
			{
				string t=line.substr(line.length()-4,4);
				int x = stoi(t);
				string z=line.substr(pos+16,5);
				exit[x]=z;
				status[x]=0;
			}
			
    	}
    	myfile.close();
    	
    	ofstream myfile ("machine.txt");
  		if (myfile.is_open())
  		{
  			myfile << "Machine Number Infos.\n\n\n";
  			myfile << "Machine Number\n";
  			for(auto it:machine)
  			{
  				myfile <<it<<endl;
			}
    		myfile.close();
  		}
  		else cout << "Unable to open file";
  		
  		ofstream myfile1 ("alloted.txt");
  		if (myfile1.is_open())
  		{
  			myfile1 << "Allotment Infos.\n\n\n";
  			myfile1 << "Machine Number\t\tAlloted Time\n";
  			for(auto it:alloted)
  			{
  				myfile1 <<it.first<<"\t\t\t"<<it.second<<endl;
			}
    		myfile1.close();
  		}
  		else cout << "Unable to open file";
  		
  		ofstream myfile2 ("arrival.txt");
  		if (myfile2.is_open())
  		{
  			myfile2 << "Arrival time Infos.\n\n\n";
  			myfile2 << "Machine Number\t\tArrival Time\n";
  			for(auto it:arrival)
  			{
  				myfile2 <<it.first<<"\t\t\t"<<it.second<<endl;
			}
    		myfile2.close();
  		}
  		else cout << "Unable to open file";
  		
  		ofstream myfile3 ("exit.txt");
  		if (myfile3.is_open())
  		{
  			myfile3 << "Exit Time Infos.\n\n\n";
  			myfile3 << "Machine Number\t\tExit Time\n";
  			for(auto it:exit)
  			{
  				myfile3 <<it.first<<"\t\t\t"<<it.second<<endl;
			}
    		myfile3.close();
  		}
  		else cout << "Unable to open file";
  		
  	}

  	else cout << "Unable to open file"; 

  	return 0;
}



