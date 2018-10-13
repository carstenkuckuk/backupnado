// Project: backupnado
// File: domain/BackupConfiguration.cpp
//
// Holds the configuration information like source directory, backup location, etc.

#include "BackupConfiguration.hpp"

#include "../helpers/filehelpers.hpp"
#include "../helpers/stringhelpers.hpp"

BackupConfiguration::BackupConfiguration()
:m_strNodeName("NodeName"), m_strSourceDirectory("."), m_strTargetDirectory("."),
m_strUserName("User Name"), m_strUserEMail("user@example.org")
{
}

BackupConfiguration::~BackupConfiguration()
{
}

std::string BackupConfiguration::GetNodeName() const
{
	return m_strNodeName;
}

void BackupConfiguration::SetNodeName(std::string strNodeName)
{
	m_strNodeName = strNodeName;
}

std::string BackupConfiguration::GetSourceDirectory() const
{
	return m_strSourceDirectory;
}

void BackupConfiguration::SetSourceDirectory(std::string strSourceDirectory)
{
	m_strSourceDirectory = strSourceDirectory;
}

std::string BackupConfiguration::GetTargetDirectory() const
{
	return m_strTargetDirectory;
}

void BackupConfiguration::SetTargetDirectory(std::string strTargetDirectory)
{
	m_strTargetDirectory = strTargetDirectory;
}

std::string BackupConfiguration::GetUserName() const
{
	return m_strUserName;
}

void BackupConfiguration::SetUserName(std::string strUserName)
{
	m_strUserName = strUserName;
}

std::string BackupConfiguration::GetUserEMail() const
{
	return m_strUserEMail;
}

void BackupConfiguration::SetUserEMail(std::string strEMail)
{
	m_strUserEMail = strEMail;
}

std::string to_string(const BackupConfiguration &refBC)
{
	std::string strResult = "BackupConfiguration("
		"NodeName='" + refBC.GetNodeName() + "', "
		"SourceDirectory='" + refBC.GetSourceDirectory() + "', "
		"TargetDirectory='" + refBC.GetTargetDirectory() + "', "
		"UserName='" + refBC.GetUserName() + "', "
		"UserEMail='" + refBC.GetUserEMail() + "'"
		")";
	return strResult;
}

bool ReadFromFile(std::string strFilename, BackupConfiguration &refBC) // true: ok, false: error occurred
{
	std::vector<std::string> rgFileContents;
	bool bSuccessfull = ReadLinesFromFileIntoVectorOfString(strFilename, rgFileContents);

	std::string strNodeName = ConfigFileContentsFindFirstEntryByNameWithDefaultValue(rgFileContents, "NodeName", refBC.GetNodeName());
	std::string strSourceDirectory = ConfigFileContentsFindFirstEntryByNameWithDefaultValue(rgFileContents, "SourceDirectory", refBC.GetSourceDirectory());
	std::string strTargetDirectory = ConfigFileContentsFindFirstEntryByNameWithDefaultValue(rgFileContents, "TargetDirectory", refBC.GetTargetDirectory());
	std::string strUserName = ConfigFileContentsFindFirstEntryByNameWithDefaultValue(rgFileContents, "UserName", refBC.GetUserName());
	std::string strUSerEMail = ConfigFileContentsFindFirstEntryByNameWithDefaultValue(rgFileContents, "UserEMail", refBC.GetUserEMail());

	refBC.SetNodeName(strNodeName);
	refBC.SetSourceDirectory(strSourceDirectory);
	refBC.SetTargetDirectory(strTargetDirectory);
	refBC.SetUserName(strUserName);
	refBC.SetUserEMail(strUSerEMail);

	return true;
}

bool WriteToFile(std::string strFilename, const BackupConfiguration &refBC) // true: ok, false: error
{
	std::vector<std::string> rgFileContents;

	rgFileContents.push_back("# Backupnado Configuration File at '" + strFilename + "'");
	rgFileContents.push_back("NodeName=" + refBC.GetNodeName());
	rgFileContents.push_back("SourceDirectory=" + refBC.GetSourceDirectory());
	rgFileContents.push_back("TargetDirectory=" + refBC.GetTargetDirectory());
	rgFileContents.push_back("UserName=" + refBC.GetUserName());
	rgFileContents.push_back("UserEMail=" + refBC.GetUserEMail());

	bool bSuccessfull = WriteVectorOfStringToFile(strFilename, rgFileContents);

	return bSuccessfull;
}
