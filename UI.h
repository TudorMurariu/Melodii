#pragma once
#include "Service.h"
#include <qwidget.h>
#include <qtablewidget.h>
#include <QAbstractTableModel>
#include <qpushbutton.h>
#include <qpainter.h>

class MyTableModel : public QAbstractTableModel {
	vector<melodie> v;
public:

	MyTableModel(vector<melodie> m) : v(m) {
	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return v.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {

		if (role == Qt::DisplayRole) {

			melodie p = v[index.row()];
			if (index.column() == 0) {
				return QString::number(p.id);
			}
			else if (index.column() == 1) {
				return QString::fromStdString(p.titlu);
			}
			else if (index.column() == 2) {
				return QString::fromStdString(p.artist);
			}
			else if (index.column() == 3) {
				return QString::number(p.rank);
			}
			else {
				int nr = 0;
				for (auto& x : v)
					if (x.rank == v[index.row()].rank && x.id != v[index.row()].id)
						nr++;
				return QString::number(nr);
			}
		}

		return QVariant{};
	}

	/*bool setData(const QModelIndex& index, const QVariant& value,int role)
	{
		if (role == Qt::EditRole) 
		{
			int row = index.row();
			int column = index.column();
		}
		return true;
	}
	Qt::ItemFlags flags(const QModelIndex& index) const override {
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	}*/


	void setMelodii(vector<melodie> m)
	{
		this->v = m;
		QModelIndex bottomRight1 = createIndex(0, 0);
		QModelIndex topLeft1 = createIndex(rowCount(), columnCount());
		emit dataChanged(bottomRight1, topLeft1);
		emit layoutChanged();
	}

};

//class Widget_Jos : public QWidget {
//
//	service& srv;
//
//public:
//
//	Widget_Jos(service& srv1) : srv(srv1){}
//
//	void update()
//	{
//		this->repaint();
//	}
//
//	void paintEvent(QPaintEvent* ev) override 
//	{
//		QPainter p(this);
//		int v[11];
//
//		for (auto& x : srv.get_list())
//			v[x.rank]++;
//
//		int s = -20;
//		for (int i = 0; i <= 10; i++)
//		{
//			s += 40;
//			p.fillRect(s, 0, 20, 60, Qt::red);
//		}
//	}
//};

class GUI : public QWidget {
	service& srv;

	QTableView* tblV = new QTableView;
	MyTableModel* model;

	QSlider* slider;
	QPushButton* UPDATE = new QPushButton("UPDATE");
	QLineEdit* nume;
	QPushButton* DELETE = new QPushButton("DELETE");
	//Widget_Jos* jos = new Widget_Jos(srv);

public:
	GUI(service& srv1) : srv(srv1)
	{
		model = new MyTableModel(srv.get_list());
		tblV->setModel(model);
		build_UI();
		connect_signals();
	}

	void build_UI();
	void connect_signals();


	void update()
	{
		this->repaint();
	}

	void paintEvent(QPaintEvent* ev) override
	{
		QPainter p(this);
		int v[11] = {0};

		for (auto& x : srv.get_list())
			v[x.rank]++;

		int s = -20;
		for (int i = 0; i <= 10; i++)
		{
			s += 40;
			p.fillRect(s, 350, 20, v[i] * 50, Qt::red);
		}
	}
};