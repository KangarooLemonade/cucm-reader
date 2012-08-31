#include <QtGui>

#include "testoutputdialog.h"

using namespace std;

TestOutputDialog::TestOutputDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	
	//open cucm file
	//set beginning variables
	ifstream cucmInput ("cucm");
	routePatternDetected = false;
	routeListDetected = false;
	routeGroupDetected = false;
	rp_number = 0;
	rl_number = 0;
	rg_number = 0;
	
	//read and store
	if (cucmInput.is_open())
		while (cucmInput.good()) {
			tempString = "";
			getline(cucmInput, settingsOutput);
			
			//ROUTE PATTERN
			if ((routePatternDetected) && (count != reqCount)) {
				switch(count) {
					case 0:
						rp_pattern[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						routePatternBrowser->append(QString::fromStdString(settingsOutput));
						break;
						
					case 1:
						rp_description[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						
					case 2:
						rp_partition[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
						
					case 3:
						if (settingsOutput == "Y")
							rp_route[rp_number] = 1;
						else
							rp_route[rp_number] = 0;
							
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
							
					case 4:
						if (settingsOutput == "Y")
							rp_urgent[rp_number] = 1;
						else
							rp_urgent[rp_number] = 0;
							
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
						
					case 5:
						rp_list[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
				}
				count += 1;
				
				//RESET COUNT
				if (count == reqCount) {
					resetCount("RP");
				}
			}
			
			
			//ROUTE LIST
			if ((routeListDetected) && (count != reqCount)) {
				switch(count) {
					case 0:
						rl_name[rl_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						routeListBrowser->append(QString::fromStdString(settingsOutput));
						break;
						
					case 1:
						rl_cluster[rl_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
					
					case 2:
						rl_group[rl_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
				}
				count += 1;
				
				//RESET COUNT
				if (count == reqCount) {
					resetCount("RL");
				}
			}
			
			
			//ROUTE GROUP
			
			if ((routeGroupDetected) && (count != reqCount)) {
				switch(count) {
					case 0:
						rg_name[rg_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						routeGroupBrowser->append(QString::fromStdString(settingsOutput));
						break;
					
					case 1:
						rg_devices[rg_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
				}
				count += 1;
				
				//RESET COUNT
				if (count == reqCount) {
					resetCount("RG");
				}
			}
			
			
			//DETECTION
			if (settingsOutput == "RoutePattern") {
				textEdit->append("Route Pattern Detected.\n");
				routePatternDetected = true;
				reqCount = 5;
				count = 0;
			}
			
			if (settingsOutput == "RouteList") {
				textEdit->append("Route List Detected.\n");
				routeListDetected = true;
				reqCount = 3;
				count = 0;
			}
			
			if (settingsOutput == "RouteGroup") {
				textEdit->append("Route Group Detected.\n");
				routeGroupDetected = true;
				reqCount = 2;
				count = 0;
			}
		}
}

void TestOutputDialog::resetCount(string type)
{
	if (type == "RP") {
		TestOutputDialog::routePatternDetected = false;
		TestOutputDialog::rp_number += 1;
		textEdit->append("End of Route Pattern.");
	}
	
	if (type == "RL") {
		TestOutputDialog::routeListDetected = false;
		TestOutputDialog::rl_number += 1;
		textEdit->append("End of Route List.");
	}
	
	if (type == "RG") {
		TestOutputDialog::routeGroupDetected = false;
		TestOutputDialog::rg_number += 1;
		textEdit->append("End of Route Group.");
	}
	TestOutputDialog::count = 0;
}