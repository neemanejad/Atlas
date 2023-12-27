#include "library_options_list.h"
#include <qfont.h>
#include <qfontdatabase.h>

LibraryOptionsList::LibraryOptionsList(QWidget* parent) : QListWidget(parent) {
	verticalScrollBar = new QScrollBar(this);
	layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignmentFlag::AlignTop);
	setLayout(layout);
	setVerticalScrollBar(verticalScrollBar);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

LibraryOptionsList::~LibraryOptionsList() {};

void LibraryOptionsList::AddLibraryOption(LibraryOption* option) {
	libraryOptions.push_back(option);
	auto item = new QListWidgetItem(this);
	QFont font = QFont("Courier", 18, QFont::Bold);
	font.setStyleHint(QFont::Monospace);
	item->setFont(font);
	item->setText(option->text());
	insertItem(count(), item);
}