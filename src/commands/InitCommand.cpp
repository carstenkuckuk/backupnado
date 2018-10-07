// Project: backupnado
// File: commands/InitCommand.cpp
//
// Performs the Init command for the backupnado command line tool

#include "InitCommand.hpp"

#include "../domain/BackupConfiguration.hpp"

#include <git2.h>
#include <git2/common.h>

#include <iostream>

static void WriteBackupnadoConfigurationFile(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory);
static void InitializeGitRepositoryForBackupOfComputerAt(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory);

int InitCommand(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory) // 0=ok, other: failure
{
	WriteBackupnadoConfigurationFile(strNodeName, strSourceDirectory, strTargetDirectory);

	InitializeGitRepositoryForBackupOfComputerAt(strNodeName, strSourceDirectory, strTargetDirectory);

	return 0;
}

static void WriteBackupnadoConfigurationFile(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory)
{
	BackupConfiguration BC;
	BC.SetNodeName(strNodeName);
	BC.SetSourceDirectory(strSourceDirectory);
	BC.SetTargetDirectory(strTargetDirectory);

	WriteToFile(".backupnado", BC);
}

static void InitializeGitRepositoryForBackupOfComputerAt(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory)
{
	git_repository *pRepo = 0;

	git_repository_init_options opts;
	git_repository_init_init_options(&opts, GIT_REPOSITORY_INIT_OPTIONS_VERSION);
	opts.description = "backupnado repository";

	int nRetVal = git_repository_init_ext(&pRepo, strTargetDirectory.c_str(), &opts);

	git_repository_free(pRepo);
}

