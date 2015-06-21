#include "stega.h"
#include "ui_stega.h"
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <bitset>
#include <QTextStream>
#include <QFile>
using namespace std;

Stega::Stega(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stega)
{
    ui->setupUi(this);
}

Stega::~Stega()
{
    delete ui;
}

void Stega::on_lineEdit_editingFinished()
{
    inputtxt=ui->lineEdit->text().toStdString();
}

void Stega::on_lineEdit_2_editingFinished()
{
    inputwav=ui->lineEdit_2->text().toStdString();
}

void Stega::on_btn_clicked()
{
    QFile inputtxt ("input, txt") ;
    QFile inputwav ("input, txt") ;
    QFile output ("outtput, txt") ;
    QTextStream infile1(&inputtxt);
    QTextStream infile2(&inputwav);
    QTextStream outfile(&output);
    if(!inputtxt.open(QIODevice::ReadOnly))
    {
       QMessageBox::information(this,"Error!","Cannot open txt file!");
       return;
    }
    if(!inputwav.open(QIODevice::ReadOnly))
    {
       QMessageBox::information(this,"Error!","Cannot open wav file!");
       return;
    }

    if(!output.open(QIODevice::ReadOnly))
    {
       QMessageBox::information(this,"Error!","Cannot open output file!");
       return;
    }

    vector<unsigned char> mas_wav;
    vector<unsigned char> mas_txt;

        for (int i = 8; i < 12; i++)
        {
            tmp += mas_wav[i];
        }
        if (tmp != wav)
        {
            cout << "Error! This file isn't wav file!";
            return 0;
        }

       if (mas_wav.size() - 44 < mas_txt.size() * 8)
       {
           cout << "Error! Increase wav file capacity." << endl;
       }

    size_t j = 44;
    for (size_t i = 0; i < mas_txt.size(); i++)
        {
            unsigned char wav = mas_wav[j];
            unsigned char txtByte = mas_txt[i];

            unsigned char bit = txtByte;

            for (size_t k = 0; k < 8; k++)
            {
                bit <<= i;
                bit >>= (7 - i);

                wav >>= 1;
                wav <<= 1;

                if (bit)
                {
                    wav += 1;
                }

                mas_wav[j] = wav;
                ++j;
                wav = mas_wav[j];
            }
    }

    for (size_t i = 0; i < mas_wav.size(); i++)
    {
        outfile << mas_wav[i];
    }
    output.close();
    inputtxt.close();
    inputwav.close();

}


