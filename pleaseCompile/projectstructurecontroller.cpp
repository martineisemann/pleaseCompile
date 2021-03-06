#include "projectstructurecontroller.h"

#include <iostream>

/**
 * @brief ProjectStructureController::ProjectStructureController
 * @param
 */
ProjectStructureController::ProjectStructureController()
{}

void ProjectStructureController::controlProjectStructure(const DirectoryList& d){
    checkFolderTreeDepth( "/app/", d.aplicationDirs() );
    checkFolderTreeDepth( "/lib/", d.libraryDirs() );
}

void ProjectStructureController::checkFolderTreeDepth( const QString match, const std::vector<QString>& dirs )
{
    for(const QString& it : dirs){       

        const int lastIdxOfSlash = it.lastIndexOf( match ) + 5;
        QString substr{it};
        substr.remove(0, lastIdxOfSlash);

        if(substr.contains("/")){
            QString errorMessage = "The project structure is not according to the structure requested by pleaseCompile. No subfolders are allowed within each library or application. \nCheck: " + it + "\n";
            throw errorMessage;
        }
    }
}
