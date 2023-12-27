#include "atlas.h"
#include "library_selection_view.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qsizepolicy.h>

Atlas::Atlas(QWidget* parent) : QWidget(parent) {
	setMinimumSize(600, 400);

	menuBar = new QMenuBar(this);
	QMenu* menu = new QMenu("Games");
	menu->addAction("Add Game", [&]() -> void {
		AddLibraryOption("newgame");
	});
	menuBar->addMenu(menu);

	BuildLibraryView();
}

Atlas::~Atlas() {}

void Atlas::AddLibraryOption(const QString& text) {
	LibraryOption* libraryOption = new LibraryOption(text);
	libraryOptionsList->AddLibraryOption(libraryOption);

	connect(libraryOptionsList, SIGNAL(libraryOptionSelected(LibraryOption*)), this, SLOT(ChangeRightPaneView(LibraryOption*)));
}

void Atlas::BuildLibraryView() {
	appContainerlayout = new QVBoxLayout();
	setLayout(appContainerlayout);

	libraryViewLayout = new QHBoxLayout();

	libraryView = new QWidget();
	libraryView->setLayout(libraryViewLayout);
	libraryOptionsList = new LibraryOptionsList(libraryView);
	librarySelectionView = new LibrarySelectionView();

	libraryViewLayout->addWidget(libraryOptionsList);
	libraryViewLayout->addWidget(librarySelectionView);

	appContainerlayout->addWidget(libraryView);
	libraryViewLayout->setStretch(0, 1);
	libraryViewLayout->setStretch(1, 2);
}

void Atlas::ChangeRightPaneView(LibraryOption* selectedOption) {
	librarySelectionView->ChangeSelection(selectedOption);
}