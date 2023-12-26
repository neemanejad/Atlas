#include "atlas.h"
#include <qpushbutton.h>
#include <qlabel.h>

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
	libraryViewLayout = new QHBoxLayout();
	leftPaneLayout = new QVBoxLayout();
	leftPaneLayout->setAlignment(Qt::AlignmentFlag::AlignTop);
	rightPaneLayout = new QVBoxLayout();
	rightPaneLayout->setAlignment(Qt::AlignmentFlag::AlignTop);

	libraryView = new QWidget(this);
	libraryView->setLayout(libraryViewLayout);
	leftPane = new QWidget(this);
	leftPane->setLayout(leftPaneLayout);
	rightPane = new QWidget(this);
	rightPane->setLayout(rightPaneLayout);

	libraryViewLayout->addWidget(leftPane);
	libraryViewLayout->addWidget(rightPane);

	rightPaneLabel = new QLabel("Initial text");
	rightPaneLayout->addWidget(rightPaneLabel);
}

void Atlas::ChangeRightPaneView(LibraryOption* selectedOption) {
	rightPaneLabel->setText(selectedOption->text());
}