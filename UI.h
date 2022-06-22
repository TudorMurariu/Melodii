#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qtablewidget.h>

class GUI : public QWidget {
	service& srv;

	QTableWidget* tabel1;

public:
	GUI(service& srv1) : srv(srv1){}

	void build_UI();
	void connect_signals();
};