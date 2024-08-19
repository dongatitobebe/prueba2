#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QGraphicsView>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    explicit cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_pushButton_ejercicio1_clicked();
    void on_pushButton_ejercicio2_clicked();
    void on_pushButton_ejercicio3_clicked();
    void on_pushButton_Salir_clicked();

    void on_comboBox_tipodetareas_currentIndexChanged(int index);
    void on_GuardarTarea_clicked();

    void on_pushButton_cambiarfigura_clicked();

    void on_pushButton_negrita_clicked();
    void on_pushButton_cursiva_clicked();
    void on_pushButton_subrayado_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Guardarproducto_clicked();

    void on_tipoproducto_activated(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_mostrarproducto_clicked();

    void on_pushButton_ejercicio4_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::cframe *ui;
};

#endif // CFRAME_H
