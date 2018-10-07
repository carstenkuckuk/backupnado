// Project: backupnado
// File: domain/BackupConfiguration.cpp
//
// Holds the configuration information like source directory, backup location, etc.

#include "BackupConfiguration.hpp"

#include "../helpers/filehelpers.hpp"
#include "../helpers/stringhelpers.hpp"

BackupConfiguration::BackupConfiguration()
:m_strNodeName("NodeName"), m_strSourceDirectory("."), m_strTargetDirectory(".")
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


std::string to_string(const BackupConfiguration &refBC)
{
	std::string strResult = "BackupConfiguration("
		"NodeName='" + refBC.GetNodeName() + "', "
		"SourceDirectory='" + refBC.GetSourceDirectory() + "', "
		"TargetDirectory='" + refBC.GetTargetDirectory() + "'"
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

	refBC.SetNodeName(strNodeName);
	refBC.SetSourceDirectory(strSourceDirectory);
	refBC.SetTargetDirectory(strTargetDirectory);

	return true;
}

bool WriteToFile(std::string strFilename, const BackupConfiguration &refBC) // true: ok, false: error
{
	std::vector<std::string> rgFileContents;

	rgFileContents.push_back("# Backupnado Configuration File at '" + strFilename + "'");
	rgFileContents.push_back("NodeName=" + refBC.GetNodeName());
	rgFileContents.push_back("SourceDirectory=" + refBC.GetSourceDirectory());
	rgFileContents.push_back("TargetDirectory=" + refBC.GetTargetDirectory());

	bool bSuccessfull = WriteVectorOfStringToFile(strFilename, rgFileContents);

	return bSuccessfull;
}
