#pragma once

#include <qwidget.h>
#include <qpushbutton.h>
#include <string>

enum LibraryOptionState {
	NOT_RUNNING,
	RUNNING
};

class LibraryOption : public QPushButton
{
Q_OBJECT
public:
	QString filepath;
	QString filename;
	explicit LibraryOption(const QString &filepath, QWidget* parent = nullptr);
	~LibraryOption();

signals:
	void libraryOptionClicked(LibraryOption*);
public slots:
	void clickedOption();

};