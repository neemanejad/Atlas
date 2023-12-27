#pragma once

#include <qwidget.h>
#include <qlistwidget.h>
#include <qscrollbar.h>
#include <qboxlayout.h>
#include "library_option_button.h"
#include <vector>
#include <unordered_map>


class LibraryOptionsList : public QListWidget
{
Q_OBJECT
public:
	explicit LibraryOptionsList(QWidget* parent = nullptr);
	~LibraryOptionsList();

	void AddLibraryOption(LibraryOption* widget);
	LibraryOption* GetLibraryOption(QString &libraryOptionText);

signals:
	void libraryOptionSelected(LibraryOption* libraryOption);
private slots:
	void selectedLibraryOption(QListWidgetItem* item);

private:
	std::unordered_map<QString, LibraryOption*> libraryOptionsMap;
	QScrollBar* verticalScrollBar;
	QVBoxLayout* layout;
};