#include <QtGui>

#include "testoutputdialog.h"

using namespace std;
using namespace boost;

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
						textEdit->append("Pattern:");
						rp_pattern[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						routePatternBrowser->append(QString::fromStdString(settingsOutput));
						break;
						
					case 1:
						textEdit->append("Description:");
						rp_description[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
						
					case 2:
						textEdit->append("Partition:");
						rp_partition[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
						
					case 3:
						textEdit->append("Routed?");
						
						if (settingsOutput == "Y")
							rp_route[rp_number] = 1;
						else
							rp_route[rp_number] = 0;
							
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
							
					case 4:
						textEdit->append("Urgent?");
					
						if (settingsOutput == "Y")
							rp_urgent[rp_number] = 1;
						else
							rp_urgent[rp_number] = 0;
							
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
						
					case 5:
						textEdit->append("Attached List:");
						rp_list[rp_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
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
						textEdit->append("Name:");
						rl_name[rl_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						routeListBrowser->append(QString::fromStdString(settingsOutput));
						break;
						
					case 1:
						textEdit->append("Cluster:");
						rl_cluster[rl_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						break;
					
					case 2:
						textEdit->append("Attached Group:");
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
						textEdit->append("Name:");
						rg_name[rg_number] = settingsOutput;
						textEdit->append(QString::fromStdString(settingsOutput));
						routeGroupBrowser->append(QString::fromStdString(settingsOutput));
						break;
					
					case 1:
						textEdit->append("Attached Devices:");
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
				reqCount = 6;
				count = 0;
			}
			
			if (settingsOutput == "RouteList") {
				textEdit->append("Route List Detected.\n");
				routeListDetected = true;
				reqCount = 4;
				count = 0;
			}
			
			if (settingsOutput == "RouteGroup") {
				textEdit->append("Route Group Detected.\n");
				routeGroupDetected = true;
				reqCount = 3;
				count = 0;
			}
		}
		
	mapToTree();
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


std::vector<std::string> TestOutputDialog::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	/* Takes a string, deliminator,
	 * and string vector. Splits the
	 * string with the deliminator
	 * and returns a vector containing
	 * each individual element. */
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	
	for (int i = 0; i != elems.size(); i++) {
		textEdit->append(QString::fromStdString(elems[i]));
	}
	
	return elems;
}


void TestOutputDialog::mapToTree()
{
	for (int i = 0; i != 15; i++) {
		if (rp_pattern[i] != "") {
			QTreeWidgetItem *patternItem = new QTreeWidgetItem();
			patternItem->setText(0, QString::fromStdString(rp_pattern[i]));
			treeWidget->addTopLevelItem(patternItem);
			vector<string> elements;
			vector<string> listVector = split(rp_list[i], ';', elements);
			
			for (int i = 0; i != listVector.size(); i++) {
				patternItem->addChild(mapList(listVector[i]));
			}
			
		}
			
			else
				break;
	}
}


QTreeWidgetItem* TestOutputDialog::mapList(string patternName)
{	
	for (int i = 0; i != 15; i++) {
		if (patternName == rl_name[i]) {
			QTreeWidgetItem *listItem = new QTreeWidgetItem();
			listItem->setText(0, QString::fromStdString(rl_name[i]));
			listItem->addChild(mapGroup(rl_group[i]));
			return listItem;
		}
		
		else
			continue;
	}
}


QTreeWidgetItem* TestOutputDialog::mapGroup(string patternName)
{
	for (int i = 0; i != 15; i++) {
		if (patternName == rg_name[i]) {
			QTreeWidgetItem *groupItem = new QTreeWidgetItem();
			groupItem->setText(0, QString::fromStdString(rg_name[i]));
			
			vector<string> elements;
			vector<string> deviceVector = split(rg_devices[i], ';', elements);
			
			for (int i = 0; i != elements.size(); i++) {
				groupItem->addChild(mapDevice(deviceVector[i]));
			}
			
			return groupItem;
		}
		
		else
			continue;
	}
}


QTreeWidgetItem* TestOutputDialog::mapDevice(string device)
{
	QTreeWidgetItem *deviceItem = new QTreeWidgetItem();
	deviceItem->setText(0, QString::fromStdString(device));
	return deviceItem;
}