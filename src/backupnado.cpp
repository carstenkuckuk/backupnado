// Project: backupnado
// File: backupnado.cpp
//
// Entry point for the backupnado command line tool

#include <git2.h>
#include <git2/common.h>

int main(int argc, char**argv)
{
	git_libgit2_init();
	git_libgit2_shutdown();
	return 0;
}

