#pragma once

#include <qwidget.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include "library_option.h"

class Atlas : public QWidget 
{
Q_OBJECT
public:
	explicit Atlas(QWidget* parent = nullptr);
	~Atlas();
	void AddLibraryOption(const QString& text);

signals:
public slots:

private slots:
	void ChangeRightPaneView(LibraryOption*);

private:
	void BuildLibraryView();
	QWidget* libraryView;
	QWidget* leftPane;
	QWidget* rightPane;
	QHBoxLayout* libraryViewLayout;
	QVBoxLayout* leftPaneLayout;
	QVBoxLayout* rightPaneLayout;

	QLabel* rightPaneLabel;
};