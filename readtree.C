//
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "math.h"
#include "string.h"
#include "TROOT.h"
#include "TFile.h"
// mrpcx1_L 一端前沿  mrpcx1_T 一端后沿  mrpcx1_TOT 一端TOT
int readtree(){
const char*datafile="tdc_time_data";
const char*treefile="CBM_test_6000V";
char buf[1024];
//define variables*********************************************************************
Float_t mrpc11_T[32],mrpc11_L[32],mrpc11_TOT[32],mrpc12_T[32],mrpc12_L[32],mrpc12_TOT[32];

Float_t mrpc21_T[32],mrpc21_L[32],mrpc21_TOT[32],mrpc22_T[32],mrpc22_L[32],mrpc22_TOT[32];

Float_t mrpc31_T[32],mrpc31_L[32],mrpc31_TOT[32],mrpc32_T[32],mrpc32_L[32],mrpc32_TOT[32];

Float_t mrpc41_T[32],mrpc41_L[32],mrpc41_TOT[32],mrpc42_T[32],mrpc42_L[32],mrpc42_TOT[32];
//creat a TTree and input data*************************************************
sprintf(buf,"%s.root",treefile);
TFile*mfile=new TFile(buf,"RECREATE");
TTree*mtree=new TTree("mtree","event");
mtree->Branch("mrpc11_T",&mrpc11_T[0],"mrpc11_T[32]/F");
mtree->Branch("mrpc11_L",&mrpc11_L[0],"mrpc11_L[32]/F");
mtree->Branch("mrpc11_TOT",&mrpc11_TOT[0],"mrpc11_TOT[32]/F");

mtree->Branch("mrpc12_T",&mrpc12_T[0],"mrpc12_T[32]/F");
mtree->Branch("mrpc12_L",&mrpc12_L[0],"mrpc12_L[32]/F");
mtree->Branch("mrpc12_TOT",&mrpc12_TOT[0],"mrpc12_TOT[32]/F");

mtree->Branch("mrpc21_T",&mrpc21_T[0],"mrpc21_T[32]/F");
mtree->Branch("mrpc21_L",&mrpc21_L[0],"mrpc21_L[32]/F");
mtree->Branch("mrpc21_TOT",&mrpc21_TOT[0],"mrpc21_TOT[32]/F");

mtree->Branch("mrpc22_T",&mrpc22_T[0],"mrpc22_T[32]/F");
mtree->Branch("mrpc22_L",&mrpc22_L[0],"mrpc22_L[32]/F");
mtree->Branch("mrpc22_TOT",&mrpc22_TOT[0],"mrpc22_TOT[32]/F");

mtree->Branch("mrpc31_T",&mrpc31_T[0],"mrpc31_T[32]/F");
mtree->Branch("mrpc31_L",&mrpc31_L[0],"mrpc31_L[32]/F");
mtree->Branch("mrpc31_TOT",&mrpc31_TOT[0],"mrpc31_TOT[32]/F");

mtree->Branch("mrpc32_T",&mrpc32_T[0],"mrpc32_T[32]/F");
mtree->Branch("mrpc32_L",&mrpc32_L[0],"mrpc32_L[32]/F");
mtree->Branch("mrpc32_TOT",&mrpc32_TOT[0],"mrpc32_TOT[32]/F");

mtree->Branch("mrpc41_T",&mrpc41_T[0],"mrpc41_T[32]/F");
mtree->Branch("mrpc41_L",&mrpc41_L[0],"mrpc41_L[32]/F");
mtree->Branch("mrpc41_TOT",&mrpc41_TOT[0],"mrpc41_TOT[32]/F");

mtree->Branch("mrpc42_T",&mrpc42_T[0],"mrpc42_T[32]/F");
mtree->Branch("mrpc42_L",&mrpc42_L[0],"mrpc42_L[32]/F");
mtree->Branch("mrpc42_TOT",&mrpc42_TOT[0],"mrpc42_TOT[32]/F");
//read data from TXT file*******************************************************************
ifstream indata;
sprintf(buf,"%s.txt",datafile);
indata.open(buf);
if(indata.bad()){ cerr<<"Open failed!!!"<<endl;return -1;}
if(indata.eof()){ cout<<"Empty!!"<<endl;return -1;}
for(;indata.good();){
	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc11_L[j/2];}
		else  indata>>mrpc11_T[(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc11_TOT[j] = mrpc11_T[j]- mrpc11_L[j];
	}

	for(int j=0;j<64;j++)
	{
		if(j%2==0){indata>>mrpc12_L[31-j/2];}
		else indata>>mrpc12_T[31-(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc12_TOT[j] = mrpc12_T[j]- mrpc12_L[j];
	}

	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc21_L[j/2];}
		else  indata>>mrpc21_T[(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc21_TOT[j] = mrpc21_T[j]- mrpc21_L[j];
	}

	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc22_L[31-j/2];}
		else  indata>>mrpc22_T[31-(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc22_TOT[j] = mrpc22_T[j]- mrpc22_L[j];
	}

	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc31_L[j/2];}
		else  indata>>mrpc31_T[(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc31_TOT[j] = mrpc31_T[j]- mrpc31_L[j];
	}

	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc32_L[31-j/2];}
		else  indata>>mrpc32_T[31-(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc32_TOT[j] = mrpc32_T[j]- mrpc32_L[j];
	}	

	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc41_L[j/2];}
		else  indata>>mrpc41_T[(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc41_TOT[j] = mrpc41_T[j]- mrpc41_L[j];
	}

	for(int j=0;j<64;j++){
		if(j%2==0){indata>>mrpc42_L[31-j/2];}
		else  indata>>mrpc42_T[31-(j-1)/2];
	}
	for(int j=0;j<32;j++)
	{
		mrpc42_TOT[j] = mrpc42_T[j]- mrpc42_L[j];
	}

	

	mtree->Fill();
}
indata.close();
//close mfile*********************

if(mfile->IsOpen()){
	mtree->Write();
}
int entries=mtree->GetEntries();
cout<<" **************The total events are "<<entries<<endl;
return 0;
}


