#include "library_selection_view.h"
#include "process_manager.h"

LibrarySelectionView::LibrarySelectionView(LibraryOption* selectedOption, QWidget* parent) : QWidget(parent)
{
	layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignmentFlag::AlignTop);
	setLayout(layout);

	label = new QLabel(this);
	executeButton = new QPushButton("Execute", this);

	connect(executeButton, SIGNAL(clicked(bool)), this, SLOT(ExecuteButtonClicked()));
	connect(this, SIGNAL(clickedExecute(QString&)), ProcessManager::GetManager(), SLOT(RunExecutable(QString&)));

	layout->addWidget(label);
	layout->addWidget(executeButton);

	if (selectedOption == nullptr) {
		label->setVisible(false);
		executeButton->setVisible(false);
		return;
	}

	label->setText(selectedOption->text());
}

LibrarySelectionView::~LibrarySelectionView() {}

void LibrarySelectionView::ChangeSelection(LibraryOption* selectedOption) {
	if (selectedOption == nullptr) return;

	executablePath = selectedOption->filepath;
	executableName = selectedOption->filename;
	label->setText(executableName);
	label->setVisible(true);
	executeButton->setVisible(true);
}

void LibrarySelectionView::ExecuteButtonClicked() {
	emit clickedExecute(executablePath);
}