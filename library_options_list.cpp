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
	
	connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(selectedLibraryOption(QListWidgetItem*)));
}

LibraryOptionsList::~LibraryOptionsList() {};

void LibraryOptionsList::AddLibraryOption(LibraryOption* option) {
	libraryOptionsMap[option->text()] = option;
	auto item = new QListWidgetItem(this);
	QFont font = QFont("Courier", 18, QFont::Bold);
	font.setStyleHint(QFont::Monospace);
	item->setFont(font);
	item->setText(option->text());
	insertItem(count(), item);
}

LibraryOption* LibraryOptionsList::GetLibraryOption(QString& libraryOptionText) {
	return libraryOptionsMap[libraryOptionText];
}

void LibraryOptionsList::selectedLibraryOption(QListWidgetItem* item) {
	LibraryOption* libraryOption = libraryOptionsMap[item->text()];
	emit libraryOptionSelected(libraryOption);
}

