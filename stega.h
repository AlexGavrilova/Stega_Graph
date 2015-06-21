#ifndef STEGA_H
#define STEGA_H

#include <QMainWindow>
#include <QDir>
namespace Ui {
class Stega;
}

class Stega : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stega(QWidget *parent = 0);
    ~Stega();

private slots:
    void on_btn_clicked();
    void on_lineEdit_editingFinished();
    void on_lineEdit_2_editingFinished();
private:
    Ui::Stega *ui;
};

#endif // STEGA_H
