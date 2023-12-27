#include "atlas.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qsizepolicy.h>
#include <qfiledialog.h>

Atlas::Atlas(QWidget* parent) : QWidget(parent) {
	setMinimumSize(600, 400);

	appContainerlayout = new QVBoxLayout();
	setLayout(appContainerlayout);

	libraryView = new LibraryView(this);

	menuBar = new QMenuBar();
	QMenu* gamesMenu = new QMenu("Games", this);
	QMenu* settingsMenu = new QMenu("Settings", this);
	gamesMenu->addAction("Add Game", [&]() -> void {
		QString filename = QFileDialog::getOpenFileName(this,
			tr("Add Game"), "", tr("Executable File (*.exe)"));

		if (filename.size() == 0) {
			return;
		}

		libraryView->AddLibraryOption(filename);
	});
	menuBar->addMenu(settingsMenu);
	menuBar->addMenu(gamesMenu);
	menuBar->adjustSize();

	appContainerlayout->addWidget(menuBar);
	appContainerlayout->addWidget(libraryView);
}

Atlas::~Atlas() {}
