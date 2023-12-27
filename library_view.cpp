#include "library_view.h"

LibraryView::LibraryView(QWidget* parent) : QWidget(parent) {
	BuildLibraryView();
}

LibraryView::~LibraryView() {}

void LibraryView::BuildLibraryView() {
	libraryViewLayout = new QHBoxLayout();

	libraryView = new QWidget();
	setLayout(libraryViewLayout);
	libraryOptionsList = new LibraryOptionsList(libraryView);
	librarySelectionView = new LibrarySelectionView(nullptr, libraryView);

	libraryViewLayout->addWidget(libraryOptionsList);
	libraryViewLayout->addWidget(librarySelectionView);

	libraryViewLayout->setStretch(0, 1);
	libraryViewLayout->setStretch(1, 2);
}

void LibraryView::AddLibraryOption(const QString& text) {
	LibraryOption* libraryOption = new LibraryOption(text);
	libraryOptionsList->AddLibraryOption(libraryOption);

	connect(libraryOptionsList, SIGNAL(libraryOptionSelected(LibraryOption*)), this, SLOT(ChangeRightPaneView(LibraryOption*)));
}

void LibraryView::ChangeRightPaneView(LibraryOption* selectedOption) {
	librarySelectionView->ChangeSelection(selectedOption);
}