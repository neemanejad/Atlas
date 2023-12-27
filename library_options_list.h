#pragma once

#include <qwidget.h>
#include <qlistwidget.h>
#include <qscrollbar.h>
#include <qboxlayout.h>
#include "library_option_button.h"
#include <vector>


class LibraryOptionsList : public QListWidget
{
Q_OBJECT
public:
	explicit LibraryOptionsList(QWidget* parent = nullptr);
	~LibraryOptionsList();

	void AddLibraryOption(LibraryOption* widget);

signals:
public slots:


private:
	std::vector<LibraryOption*> libraryOptions;
	QScrollBar* verticalScrollBar;
	QVBoxLayout* layout;
};