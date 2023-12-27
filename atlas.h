#pragma once

#include <qwidget.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qmenubar.h>
#include "library_option_button.h"
#include "library_selection_view.h"
#include "library_options_list.h"
#include "library_view.h"

class Atlas : public QWidget 
{
Q_OBJECT
public:
	explicit Atlas(QWidget* parent = nullptr);
	~Atlas();

signals:
private slots:

private:
	QVBoxLayout* appContainerlayout;
	QMenuBar* menuBar;
	LibraryView* libraryView;
};