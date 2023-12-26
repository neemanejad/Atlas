#include "atlas.h"
#include <qpushbutton.h>
#include <qlabel.h>

Atlas::Atlas(QWidget* parent) : QWidget(parent) {
	setMinimumSize(600, 400);

	BuildLibraryView();
}

Atlas::~Atlas() {}

void Atlas::AddLibraryOption(const QString& text) {
	QPushButton* libraryOption = new QPushButton(text);
	leftPaneLayout->addWidget(libraryOption);
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

	QLabel* placeholderLabelText = new QLabel("Hello");
	rightPaneLayout->addWidget(placeholderLabelText);
}