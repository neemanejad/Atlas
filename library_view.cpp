#include "library_view.h"
#include "process_manager.h"

LibraryView::LibraryView(QWidget* parent) : QWidget(parent) {
	BuildLibraryView();

	connect(ProcessManager::GetManager(), SIGNAL(threadStarted(QString&)), this, SLOT(SetLibraryOptionAsRunning(QString&)));
	connect(ProcessManager::GetManager(), SIGNAL(threadFinished(QString&)), this, SLOT(SetLibraryOptionAsNotRunning(QString&)));

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

void LibraryView::SetLibraryOptionAsNotRunning(QString& filepath) {
	libraryOptionsList->SetLibraryOptionState(filepath, LibraryOptionState::NOT_RUNNING);
	librarySelectionView->SetLibrarySelectionState(LibraryOptionState::NOT_RUNNING);
}

void LibraryView::SetLibraryOptionAsRunning(QString& filepath) {
	libraryOptionsList->SetLibraryOptionState(filepath, LibraryOptionState::RUNNING);
	librarySelectionView->SetLibrarySelectionState(LibraryOptionState::RUNNING);
}