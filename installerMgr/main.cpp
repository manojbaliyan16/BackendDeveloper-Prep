
#include <mutex>
#include <iostream>
#include <dlt/dlt.h>
#include <list>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../src/pf/installmanager/CSwdlJobFactory.hpp"
#include "../src/pf/installmanager/CInstallerJobManager.hpp"

#define BTLD_BIT 2
#define CHUNKSIZE 65533

DLT_DECLARE_CONTEXT(SoftwareUpdateContext);
int LOG_LEVEL=1;
using namespace std;

map<string, string> partMetaInfo;
void chunkFile(string fullFilePath, uint32_t chunkSize, long int imageSize, string partName) {
	ifstream fileStream;
	//string partName="IOC";
	partMetaInfo.insert(pair<string, string>("TOTAL_SIZE", to_string(imageSize)));
	partMetaInfo.insert(pair<string, string>("OFFSET", to_string(0)));
	partMetaInfo.insert(pair<string, string>("BUFFER_SIZE", to_string(chunkSize)));

	fileStream.open(fullFilePath, ios::in|ios::binary);

	cout << "goint to open the file " <<endl;
	// File open a success
	if (fileStream.is_open()) 
	{
		ofstream output;
		int counter = 1;
		char *buffer = new char[chunkSize];
		
		CInstallerJobManager::createInstance("/etc/swupd/swup_config.ini");
		if(CInstallerJobManager::getInstance()->createInstaller(partName, imageSize))
		{
			cout << "**************** Installer created Successfully  " <<endl;
		}
		else
		{
			cout << "**************** Installer creation Failed  " <<endl;
		}

		while (!fileStream.eof())
		{
			cout << "In While loop " << counter <<endl;
			int pos=fileStream.tellg();
			cout << "After setting the ptr \""<< "\" tellg() returns " << pos << '\n';
			
			fileStream.read(buffer,chunkSize);
			cout << "Going to write " << fileStream.gcount() << " Bytes of data " << endl;
			usleep(100);
			partMetaInfo.find("OFFSET")->second = to_string(pos);
			partMetaInfo.find("BUFFER_SIZE")->second=to_string(fileStream.gcount());

			CInstallerJobManager::getInstance()->updateBuffer(partName, buffer, partMetaInfo);

			counter++;
		}
		delete(buffer);
		fileStream.close();
	}
	else 
	{
		cout << "Error opening file!" << endl;

	}
}
int main(int argc, char **argv) 
{
	if(argc < 4)
	{
        cout << "Argument 1: Total Size of Image file in Bytes " << endl;
        cout << "Argument 2: Image file Path  " << endl;
        cout << "Argument 3: PartName for Installer : Like IOC " << endl;
        cout << " Note : Pass the Total size(Bytes) of Image and Path of the Image as an Argument " << endl;
		exit (EXIT_FAILURE);
    }	 	
    long int fileSize=stol(argv[1]);
	string fullFilePath=argv[2];
	string partName=argv[3];

	DLT_REGISTER_CONTEXT(SoftwareUpdateContext,"INST", "Software Update Manager installers Context");

	chunkFile(fullFilePath, CHUNKSIZE, fileSize,partName);
	DLT_UNREGISTER_CONTEXT(SoftwareUpdateContext);
	DLT_UNREGISTER_APP();
	 return 0;
}





