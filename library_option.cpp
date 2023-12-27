#include "library_option_button.h"

LibraryOption::LibraryOption(const QString &text, QWidget* parent) : QPushButton(text, parent) {
	connect(this, SIGNAL(clicked(bool)), this, SLOT (clickedOption()));
}

LibraryOption::~LibraryOption() {}

void LibraryOption::clickedOption() {
	emit libraryOptionClicked(this);
}