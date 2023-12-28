#pragma once

#include <qwidget.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include "library_option_button.h"

class LibrarySelectionView : public QWidget
{
Q_OBJECT
public:
	explicit LibrarySelectionView(LibraryOption* selectedOption = nullptr, QWidget* parent = nullptr);
	~LibrarySelectionView();
	void ChangeSelection(LibraryOption* selectedOption);

signals:
	void clickedExecute(QString& executablePath);
private slots:
	void ExecuteButtonClicked();

private:
	QString executablePath;
	QString executableName;
	QVBoxLayout* layout;
	QLabel* label;
	QPushButton* executeButton;
};