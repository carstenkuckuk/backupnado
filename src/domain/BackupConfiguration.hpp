// Project: backupnado
// File: domain/BackupConfiguration.hpp
//
// Holds the configuration information like source directory, backup location, etc.

#ifndef __BACKUPNADO_DOMAIN_BACKUPCONFIGURATION_HPP__
#define __BACKUPNADO_DOMAIN_BACKUPCONFIGURATION_HPP__

#include <string>

// This class contains all the configuration information for the regular backup job, mainly the path to the 
// directory we want to backup, and the path to the location where we want to store the backups. As we want to
// use the same backup location for backups of different computers, we also need to have a computer name or node name
// to distinguish these backups. Later on, we will have backup intervall information, and also more than one source
// directory for the backups, but for our first version, we need to keep everything as simple as possible.
// The information in this class will be stored in a configuration file at ~/.backupnado.conf

class BackupConfiguration
{
public:
	BackupConfiguration();
	virtual ~BackupConfiguration();

	std::string GetNodeName() const;
	void SetNodeName(std::string strNodeName);
	std::string GetSourceDirectory() const;
	void SetSourceDirectory(std::string strSourceDirectory);
	std::string GetTargetDirectory() const;
	void SetTargetDirectory(std::string strTargetDirectory);
	std::string GetUserName() const;
	void SetUserName(std::string strUserName);
	std::string GetUserEMail() const;
	void SetUserEMail(std::string strEMail);
protected:
	std::string m_strNodeName;			// Name of our computer. Used as (part of) branch name in backup
	std::string m_strSourceDirectory;	// We want to backup everything that is in this directory
	std::string m_strTargetDirectory;	// This is where we want to store the backups
	std::string m_strUserName;			// User Name used for the commits to the repository
	std::string m_strUserEMail;			// E-Mail address used for the commits to the repository
};

std::string to_string(const BackupConfiguration &refBC);

bool ReadFromFile(std::string strFilename, BackupConfiguration &refBC); // true: ok, false: error occurred
bool WriteToFile(std::string strFilename, const BackupConfiguration &refBC); // true: ok, false: error

#endif

