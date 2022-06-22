#include "UI.h"
#include <qlayout.h>
#include <qdebug.h>
#include <qlineedit.h>
#include <qmessagebox.h>

void GUI::build_UI()
{
	QVBoxLayout* mainly = new QVBoxLayout;
	QWidget* a = new QWidget;

	QHBoxLayout* hl = new QHBoxLayout;
	a->setLayout(hl);
	hl->addWidget(tblV);
	 
	QWidget* w1 = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	
	w1->setLayout(vl);

	nume = new QLineEdit;
	slider = new QSlider(Qt::Horizontal);

	vl->addWidget(nume);
	vl->addWidget(slider);
	vl->addWidget(UPDATE);
	vl->addWidget(DELETE);

	hl->addWidget(w1);

	QWidget* b = new QWidget;
	QHBoxLayout* hl2 = new QHBoxLayout;
	b->setLayout(hl2);

	QPushButton* aux = new QPushButton;
	aux->setVisible(false);
	hl2->addWidget(aux);

	mainly->addWidget(a);
	mainly->addWidget(b);
	mainly->addWidget(b);
	mainly->addWidget(b);
	mainly->addWidget(b);
	mainly->addWidget(b);
	mainly->addWidget(b);
	this->setLayout(mainly);
}


void GUI::connect_signals()
{
	QObject::connect(UPDATE, &QPushButton::clicked, [&]() {
		
		if (!tblV->selectionModel()->selectedIndexes().isEmpty())
		{
			int row_num = tblV->selectionModel()->selectedIndexes().at(0).row();
			auto id_index = tblV->model()->index(row_num, 0);
			int id = tblV->model()->data(id_index, Qt::DisplayRole).toString().toInt();

			string titlu_nou = nume->text().toStdString();
			int rank_nou = (slider->value() + 6) / 10;

			QMessageBox::warning(this, QString::fromStdString(to_string(rank_nou)), "meow");

			srv.modifica(id, rank_nou, titlu_nou);
			srv.Sorteaza_Lista();

			model->setMelodii(srv.get_list());
			update();
		}
		else
		{
			QMessageBox::warning(this, "trebuie selectata o casuta","");
		}
		});

	QObject::connect(DELETE, &QPushButton::clicked, [&]() {

		if (!tblV->selectionModel()->selectedIndexes().isEmpty())
		{
			int row_num = tblV->selectionModel()->selectedIndexes().at(0).row();
			auto id_index = tblV->model()->index(row_num, 0);
			int id = tblV->model()->data(id_index, Qt::DisplayRole).toString().toInt();
			
			string err = srv.sterge(id);

			if (err != "")
			{
				QMessageBox::warning(this, "Ultima melodie", "a artistului.");
			}

			srv.Sorteaza_Lista();
			model->setMelodii(srv.get_list());
			update();
		}
		else
		{
			QMessageBox::warning(this, "trebuie selectata o casuta", "");
		}

		});
}