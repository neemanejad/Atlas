#include "library_selection_view.h"
#include "process_manager.h"

LibrarySelectionView::LibrarySelectionView(LibraryOption* selectedOption, QWidget* parent) : QWidget(parent)
{
	layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignmentFlag::AlignTop);
	setLayout(layout);

	QFont labelFont = QFont("", 24, QFont::ExtraBold);
	QFont executButtonFont = QFont("", 18, QFont::Bold);

	label = new QLabel(this);
	label->setFont(labelFont);
	executeButton = new QPushButton("Execute", this);
	executeButton->setFont(executButtonFont);
	executeButton->setFixedSize(150, 70);

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

void LibrarySelectionView::SetLibrarySelectionState(LibraryOptionState state) {
	QPalette palette = executeButton->palette();
	switch (state) {
	case LibraryOptionState::NOT_RUNNING:
		palette.setColor(QPalette::Button, QColor(Qt::white));
		break;
	case LibraryOptionState::RUNNING:
		palette.setColor(QPalette::Button, QColor(Qt::green));
		break;
	}

	executeButton->setAutoFillBackground(true);
	executeButton->setPalette(palette);
}