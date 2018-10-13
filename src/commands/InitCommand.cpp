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
static void InitializeGitRepositoryForBackupOfComputerAt(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory, std::string strUserName, std::string strUserEMail);

int InitCommand(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory, std::string strUserName, std::string strUserEMail) // 0=ok, other: failure
{
	WriteBackupnadoConfigurationFile(strNodeName, strSourceDirectory, strTargetDirectory);

	InitializeGitRepositoryForBackupOfComputerAt(strNodeName, strSourceDirectory, strTargetDirectory, strUserName, strUserEMail);

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

static git_commit* CreateEmptyCommit(git_repository *pRepo, std::string strUserName, std::string strUserEMail);
static void CreateBranchFromEmptyCommit(git_repository *pRepo, git_commit *pCommit, std::string strBranchName);
static void InitializeGitRepositoryForBackupOfComputerAt(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory, std::string strUserName, std::string strUserEMail)
{
	git_repository *pRepo = 0;

	git_repository_init_options opts;
	git_repository_init_init_options(&opts, GIT_REPOSITORY_INIT_OPTIONS_VERSION);
	opts.flags |= GIT_REPOSITORY_INIT_BARE | GIT_REPOSITORY_INIT_MKDIR | GIT_REPOSITORY_INIT_MKPATH;;
	// Mit NO_REINIT arbeiten um zu testen, ob das Repo bereits existiert
	opts.description = "backupnado repository";

	int nRetVal = git_repository_init_ext(&pRepo, strTargetDirectory.c_str(), &opts);

	git_commit *pCommit = CreateEmptyCommit(pRepo, strUserName, strUserEMail);
	CreateBranchFromEmptyCommit(pRepo, pCommit, strNodeName);

	git_repository_free(pRepo);
}

static git_commit* CreateEmptyCommit(git_repository *pRepo, std::string strUserName, std::string strUserEMail)
{
	git_signature *sig=0;
	int nRet1 = git_signature_now(&sig, strUserName.c_str(), strUserEMail.c_str() );

	git_index *index=0;
	int nRet2 = git_repository_index(&index, pRepo);


	git_oid tree_id;
	int nRet3 = git_index_write_tree(&tree_id, index);
	git_index_free(index);

	git_tree *tree = 0;
	int nRet4 = git_tree_lookup(&tree, pRepo, &tree_id);

	git_oid commit_id;
	int nRet5 = git_commit_create_v(
			&commit_id, pRepo, "HEAD", sig, sig,
		NULL, 
		"This is the initial commit of a Backupnado repository. This repository contains computer backups "
		"in its branches. For further information please read through the backupnado documentation.", tree, 0);
	git_commit *pCommit = 0;
	int nRet6 = git_commit_lookup(&pCommit, pRepo, &commit_id);

	git_tree_free(tree);
	git_signature_free(sig);
	return pCommit;
}

static void CreateBranchFromEmptyCommit(git_repository *pRepo, git_commit *pCommit, std::string strBranchName)
{
	git_reference *pRef = 0;

	int nRet1 = git_branch_create(&pRef, pRepo, strBranchName.c_str(), pCommit, 0);


}
