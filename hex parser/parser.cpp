#include<iostream>
#include<fstream>

using namespace std;

int main(){
	int lineCounter=0;
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	string line;
	string outputString="unsigned int iMData[256]={";
	while (getline(inFile, line))
	{
	    if(lineCounter>=1 && lineCounter<=256){
	    	outputString+="0x"+line;
			if(lineCounter<256)outputString+=",";	
		}
	    lineCounter++;
	}
	for(int i=lineCounter;i<=256;i++){
		outputString+="0";
		if(i<256)outputString+=",";
	}
	outputString+="};";
	outFile<<outputString;
	inFile.close();
	outFile.close();
	return 0;
}
