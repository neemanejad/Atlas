#pragma once

#include <qwidget.h>
#include <qmenubar.h>
#include "library_options_list.h"
#include "library_selection_view.h"

class LibraryView : public QWidget
{
	Q_OBJECT
public:
	explicit LibraryView(QWidget* parent = nullptr);
	~LibraryView();
	void AddLibraryOption(const QString& text);

signals:
private slots:
	void ChangeRightPaneView(LibraryOption*);

private:
	QMenuBar* menuBar;
	QWidget* libraryView;
	LibraryOptionsList* libraryOptionsList;
	LibrarySelectionView* librarySelectionView;

	QHBoxLayout* libraryViewLayout;

	void BuildLibraryView();
};