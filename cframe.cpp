
#include "cframe.h"
#include "ui_cframe.h"
#include "tarea_diaria.h"
#include "tarea_semanal.h"
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QPolygonF>


cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);


    connect(ui->pushButton_ejercicio1, &QPushButton::clicked, this, &cframe::on_pushButton_ejercicio1_clicked);
    connect(ui->pushButton_ejercicio2, &QPushButton::clicked, this, &cframe::on_pushButton_ejercicio2_clicked);
    connect(ui->pushButton_ejercicio3, &QPushButton::clicked, this, &cframe::on_pushButton_ejercicio3_clicked);
    connect(ui->pushButton_Salir, &QPushButton::clicked, this, &cframe::close);

    connect(ui->comboBox_tipodetareas, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &cframe::on_comboBox_tipodetareas_currentIndexChanged);
    connect(ui->pushButton_cambiarfigura, &QPushButton::clicked, this, &cframe::on_pushButton_cambiarfigura_clicked);
    connect(ui->Guardarproducto, &QPushButton::clicked, this, &cframe::on_Guardarproducto_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &cframe::on_pushButton_4_clicked);


    connect(ui->tipoproducto, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &cframe::on_tipoproducto_activated);


    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget_4->setCurrentIndex(0);
}

cframe::~cframe()
{
    delete ui;
}


void cframe::on_pushButton_ejercicio1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void cframe::on_pushButton_ejercicio2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void cframe::on_pushButton_ejercicio3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void cframe::on_pushButton_Salir_clicked()
{
    close();
}


void cframe::on_GuardarTarea_clicked()
{
    QString titulo = ui->lineEdit_titulodelatarea->text();
    QString descripcion = ui->lineEdit_descripciones->text();
    QString fecha = ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    QString tipo = ui->comboBox_tipodetareas->currentText();

    TareaBase* tarea = nullptr;

    if (tipo == "Tareas Diarias") {
        tarea = new TareaDiaria(titulo.toStdString(), descripcion.toStdString(), fecha.toStdString());
    } else if (tipo == "Tareas Semanales") {
        tarea = new TareaSemanal(titulo.toStdString(), descripcion.toStdString(), fecha.toStdString());
    }

    if (tarea) {
        ui->textEdit_mostratareas->append(QString("Título: %1\nDescripción: %2\nFecha: %3\nTipo: %4\n")
                                              .arg(QString::fromStdString(tarea->getTitulo()))
                                              .arg(QString::fromStdString(tarea->getDescripcion()))
                                              .arg(QString::fromStdString(tarea->getFecha()))
                                              .arg(QString::fromStdString(tarea->getTipo())));
        delete tarea;
    } else {
        QMessageBox::warning(this, "Error", "Tipo de tarea no válido.");
    }
}


void cframe::on_comboBox_tipodetareas_currentIndexChanged(int index)
{
    ui->stackedWidget_2->setCurrentIndex(index);
}


void cframe::on_pushButton_cambiarfigura_clicked()
{
    QString figuraSeleccionada = ui->comboBox_figura->currentText();
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    if (figuraSeleccionada == "Cuadrado") {
        QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 100, 100);
        scene->addItem(rect);
    } else if (figuraSeleccionada == "Triangulo") {
        QPolygonF triangle;
        triangle << QPointF(0, 100) << QPointF(50, 0) << QPointF(100, 100);
        QGraphicsPolygonItem *polygon = new QGraphicsPolygonItem(triangle);
        scene->addItem(polygon);
    } else if (figuraSeleccionada == "Circulo") {
        QGraphicsEllipseItem* circulo = new QGraphicsEllipseItem(50, 50, 200, 200);
        circulo->setBrush(Qt::blue);
        scene->addItem(circulo);
    }
}


void cframe::on_pushButton_negrita_clicked()
{
    QTextCursor cursor = ui->textEdit_ejercicio3->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontWeight(format.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    cursor.setCharFormat(format);
    ui->textEdit_ejercicio3->setTextCursor(cursor);
}

void cframe::on_pushButton_cursiva_clicked()
{
    QTextCursor cursor = ui->textEdit_ejercicio3->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontItalic(!format.fontItalic());
    cursor.setCharFormat(format);
    ui->textEdit_ejercicio3->setTextCursor(cursor);
}

void cframe::on_pushButton_subrayado_clicked()
{
    QTextCursor cursor = ui->textEdit_ejercicio3->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontUnderline(!format.fontUnderline());
    cursor.setCharFormat(format);
    ui->textEdit_ejercicio3->setTextCursor(cursor);
}


void cframe::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void cframe::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}


void cframe::on_Guardarproducto_clicked()
{QString nombre = ui->nombreproducto->text();
    QString precio = ui->precioproducto->text();
    QString descripcion = ui->descripcion->text();
    QString tipoProducto = ui->tipoproducto->currentText();
    QString detallesAdicionales;


    QWidget* widgetActual = ui->stackedWidget_4->currentWidget();
    if (widgetActual) {
        QLineEdit* detallesLineEdit = widgetActual->findChild<QLineEdit*>("detallesLineEdit");
        if (detallesLineEdit) {
            detallesAdicionales = detallesLineEdit->text();
        } else {

            qDebug() << "No se encontró el QLineEdit con el nombre 'detallesLineEdit'.";
        }
    } else {

        qDebug() << "No se encontró el widget actual en el stackedWidget_4.";
    }

    QMessageBox::information(this, "Producto Guardado", QString("Nombre: %1\nPrecio: %2\nDescripción: %3\nTipo de Producto: %4\nDetalles: %5")
                                                            .arg(nombre)
                                                            .arg(precio)
                                                            .arg(descripcion)
                                                            .arg(tipoProducto)
                                                            .arg(detallesAdicionales)
                             );
}




void cframe::on_tipoproducto_activated(int index)
{
    ui->stackedWidget_4->setCurrentIndex(index);
}


void cframe::on_pushButton_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void cframe::on_pushButton_7_clicked()
{
   ui->stackedWidget_3->setCurrentIndex(1);
}


void cframe::on_mostrarproducto_clicked()
{

}


void cframe::on_pushButton_ejercicio4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void cframe::on_pushButton_4_clicked()
{

}

void cframe::on_pushButton_5_clicked()
{
   ui->stackedWidget_3->setCurrentIndex(2);
}

