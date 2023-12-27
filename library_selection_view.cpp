#include "library_selection_view.h"

LibrarySelectionView::LibrarySelectionView(LibraryOption* selectedOption, QWidget* parent) : QWidget(parent)
{
	layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignmentFlag::AlignTop);
	setLayout(layout);

	label = new QLabel(this);
	executeButton = new QPushButton("Execute", this);

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

	label->setText(selectedOption->text());
	label->setVisible(true);
	executeButton->setVisible(true);
}