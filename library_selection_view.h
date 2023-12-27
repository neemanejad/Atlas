#pragma once

#include <qwidget.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include "library_option.h"

class LibrarySelectionView : public QWidget
{
Q_OBJECT
public:
	explicit LibrarySelectionView(LibraryOption* selectedOption = nullptr, QWidget* parent = nullptr);
	~LibrarySelectionView();
	void ChangeSelection(LibraryOption* selectedOption);

signals:
private slots:

private:
	QVBoxLayout* layout;
	QLabel* label;
	QPushButton* executeButton;
};