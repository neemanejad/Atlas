#include "library_option_button.h"

LibraryOption::LibraryOption(const QString &path, QWidget* parent) : QPushButton(path, parent) {
	filepath = QString(path.toStdString().c_str());
	auto stdStringFilepath = filepath.toStdString();
	auto stdExecutable = stdStringFilepath.substr(stdStringFilepath.find_last_of("/") + 1);
	filename = QString(stdExecutable.c_str());

	setText(filename);

	connect(this, SIGNAL(clicked(bool)), this, SLOT (clickedOption()));
}

LibraryOption::~LibraryOption() {}

void LibraryOption::clickedOption() {
	emit libraryOptionClicked(this);
}