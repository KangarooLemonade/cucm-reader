#ifndef TESTOUTPUTDIALOG_H
#define TESTOUTPUTDIALOG_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "ui_testoutputdialog.h"

class TestOutputDialog : public QDialog, public Ui::TestOutputDialog
{
	Q_OBJECT
	
public:
	TestOutputDialog(QWidget *parent = 0);
	
private:
	QString settingsInput;
	std::string settingsOutput;
	QString qSettingsOutput;
	QString tempString;
	
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
	
private slots:
	void resetCount(std::string type);
};

#endif //TESTOUTPUTDIALOG_H