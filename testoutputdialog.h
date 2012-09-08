#ifndef TESTOUTPUTDIALOG_H
#define TESTOUTPUTDIALOG_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "ui_testoutputdialog.h"

class TestOutputDialog : public QDialog, public Ui::TestOutputDialog
{
	Q_OBJECT
	
public:
	TestOutputDialog(QWidget *parent = 0);
	
private:
	std::string settingsOutput;
	QString tempString;
	
	//detection vars
	bool routePatternDetected;
	bool routeListDetected;
	bool routeGroupDetected;
	int count;
	int reqCount;
	
	//route pattern vars
	int rp_number;
	std::string rp_pattern[15];
	std::string rp_description[15];
	std::string rp_partition[15];
	int rp_route[15];
	int rp_urgent[15];
	std::string rp_list[15];
	
	//route list vars
	int rl_number;
	std::string rl_name[15];
	std::string rl_cluster[15];
	std::string rl_group[15];
	
	//route group vars
	int rg_number;
	std::string rg_name[15];
	std::string rg_devices[15];
	std::string tempDeviceList[50];
	
private slots:
	//route section
	void resetCount(std::string type);
	
	std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
	
	void mapToTree();
	QTreeWidgetItem* mapList(std::string patternName);
	QTreeWidgetItem* mapGroup(std::string patternName);
	QTreeWidgetItem* mapDevice(std::string device);
};

#endif //TESTOUTPUTDIALOG_H