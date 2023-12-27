#pragma once

#include <qwidget.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qmenubar.h>
#include "library_option_button.h"
#include "library_selection_view.h"
#include "library_options_list.h"

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
	QMenuBar* menuBar;
	QWidget* libraryView;
	LibraryOptionsList* libraryOptionsList;
	LibrarySelectionView* librarySelectionView;

	QVBoxLayout* appContainerlayout;
	QHBoxLayout* libraryViewLayout;

	void BuildLibraryView();

};