#include "atlas.h"
#include "library_selection_view.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qsizepolicy.h>

Atlas::Atlas(QWidget* parent) : QWidget(parent) {
	setMinimumSize(600, 400);

	BuildLibraryView();
}

Atlas::~Atlas() {}

void Atlas::AddLibraryOption(const QString& text) {
	LibraryOption* libraryOption = new LibraryOption(text);
	leftPaneLayout->addWidget(libraryOption);

	connect(libraryOption, SIGNAL(libraryOptionClicked(LibraryOption*)), this, SLOT(ChangeRightPaneView(LibraryOption*)));
}

void Atlas::BuildLibraryView() {
	appContainerlayout = new QVBoxLayout();
	setLayout(appContainerlayout);

	libraryViewLayout = new QHBoxLayout();
	leftPaneLayout = new QVBoxLayout();
	leftPaneLayout->setAlignment(Qt::AlignmentFlag::AlignTop);

	libraryView = new QWidget();
	libraryView->setLayout(libraryViewLayout);
	leftPane = new QWidget(libraryView);
	leftPane->setLayout(leftPaneLayout);
	librarySelectionView = new LibrarySelectionView();

	libraryViewLayout->addWidget(leftPane);
	libraryViewLayout->addWidget(librarySelectionView);

	appContainerlayout->addWidget(libraryView);
}

void Atlas::ChangeRightPaneView(LibraryOption* selectedOption) {
	librarySelectionView->ChangeSelection(selectedOption);
}