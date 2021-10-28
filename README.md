# Data_Clustering


## Clone the repo by running the following commad:

git clone https://github.com/aniruddha-5/Data_Clustering.git

## Getting Started:

After cloning the repo execute "data_clustering.exe" to get the neccessary datas from the log file.

## Directory Structure:

machine.txt ----> stores the machine number </br>
arrival.txt ----> stores the arrival time </br>
exit.txt ----> stores the exit time </br>
alloted.txt ----> stores the alloted time to a particular machine </br>

## Data Structures:

vector<int> machine;   ---------> to store unique machine id. </br>
unordered_map<int,string> arrival;    ---------> to map unique machine id and arrival time. </br>
unordered_map<int,string> exit;       ---------> to map unique machine id and exit time.  </br>
unordered_map<int,int> alloted;       ---------> to map unique machine id and alloted time. </br>
unordered_map<int,int> status;        ---------> to map unique machine id with their status.  </br>
