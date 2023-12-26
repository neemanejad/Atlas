#pragma once

#include <qwidget.h>
#include <qpushbutton.h>

class LibraryOption : public QPushButton
{
Q_OBJECT
public:
	explicit LibraryOption(const QString &text, QWidget* parent = nullptr);
	~LibraryOption();

signals:
	void libraryOptionClicked(LibraryOption*);
public slots:
	void clickedOption();

};