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
	libraryOptionsMap[option->filepath] = option;
	auto item = new QListWidgetItem(this);
	itemsMap[option->filepath] = item;
	QFont font = QFont("Courier", 12, QFont::Bold);
	font.setStyleHint(QFont::Monospace);
	item->setFont(font);
	item->setText(option->text());
	item->setData(Qt::ItemDataRole::UserRole, option->filepath);
	insertItem(count(), item);
	SetLibraryOptionState(option->filepath, LibraryOptionState::NOT_RUNNING);
}

LibraryOption* LibraryOptionsList::GetLibraryOption(QString& libraryOptionText) {
	return libraryOptionsMap[libraryOptionText];
}

void LibraryOptionsList::selectedLibraryOption(QListWidgetItem* item) {
	LibraryOption* libraryOption = libraryOptionsMap[item->data(Qt::ItemDataRole::UserRole).toString()];
	emit libraryOptionSelected(libraryOption);
}

void LibraryOptionsList::SetLibraryOptionState(QString& filepath, LibraryOptionState state) {
	auto item = itemsMap[filepath];

	QColor color;
	switch (state) {
	case LibraryOptionState::NOT_RUNNING:
		color = QColor(Qt::GlobalColor::white);
		break;
	case LibraryOptionState::RUNNING:
		color = QColor(Qt::GlobalColor::green);
		break;
	}
	item->setBackgroundColor(color);
}

