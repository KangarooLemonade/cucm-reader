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
						break;
						
					case 1:
						rp_partition[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
						
					case 2:
						if (settingsOutput == "Y")
							rp_route[rp_number] = 1;
						else
							rp_route[rp_number] = 0;
							
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
							
					case 3:
						if (settingsOutput == "Y")
							rp_urgent[rp_number] = 1;
						else
							rp_urgent[rp_number] = 0;
							
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
				}
				count += 1;
				
				//RESET COUNT
				if (count == reqCount) {
					resetCount();
				}
			}
			
			//ROUTE LIST
			
			//GENERAL DETECTION
			if (settingsOutput == "RoutePattern") {
				textEdit->append("Route Pattern Detected.\n");
				routePatternDetected = true;
				reqCount = 4;
				count = 0;
			}
		}
}

void TestOutputDialog::resetCount()
{
	TestOutputDialog::routePatternDetected = false;
	TestOutputDialog::routeListDetected = false;
	TestOutputDialog::routeGroupDetected = false;
	TestOutputDialog::count = 0;
}