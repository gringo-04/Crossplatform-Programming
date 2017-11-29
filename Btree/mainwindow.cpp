#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>

#include <QPushButton>
#include <QLabel>

int mas[15];
int lp = 0;
int rp = 0;
int appex = 0;
int root = 0;
int max =0;
int min = 0;
int temp = 0;
int element = 0;
int element_2 = 0;
int lab = -1;
int stop = 0;


int left(int L)
{
    L = L*2 + 1;
    return L;
}
int right(int R)
{
    R = (R+1) * 2;
    return R;
}

QLabel *label[15];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Push()));
    connect(ui ->pushButton_2, SIGNAL(clicked()), this, SLOT(Pop()));
    connect(ui ->pushButton_3, SIGNAL(clicked()), this, SLOT(Find()));
    for (int r = 0; r < 17; r++)
    {
        mas[r] = -1;
    }

    int y = 40;
    int hw = 40;
    int k = 0;
    int x =0;
    int hj = 0;

    for (int q = 1; q <9; q=q*2)
    {
        k = width()/(q+1);
        for(int s = 1; s <= q; s++)
        {
            x = k * s;
            label[hj] = new QLabel(this);
            label[hj]->setGeometry(x, y, hw, hw);
            ++hj;
        }
        y += 100;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Style(int q, int lab)
{
    switch (q) {
    case 0:
        label[lab]->setText("");
        label[lab]->setStyleSheet("");
        break;
    case 1:
        label[lab]->setStyleSheet("border: 2px solid green;"
                                 "font-family: Courier New;"
                                 "font-size: 10px;"
                                 "border-radius: 20px;"
                                 "background-color: white;""qproperty-alignment: AlignCenter;");
        label[lab]->setText(QString::number(mas[lab]));
        break;
    case 2:
        label[lab]->setStyleSheet("border: 4px solid red;"
                                         "font-family: Courier New;"
                                         "font-size: 10px;"
                                         "border-radius: 20px;"
                                         "background-color: white;""qproperty-alignment: AlignCenter;");
    default:
        break;
    }
}


void PUSH(int element_1)
{
    do
    {
        if(element_1 < mas[temp])
        {
            if(mas[temp] != -1)
            {temp = left(temp);}
            else
            {
                mas[temp] = element_1;
                Style(1,temp);
                stop = 4;
            }
   }
        if(element_1 > mas[temp])
        {
            if(mas[temp] != -1)
            {temp = right(temp);}
            else
            {
                mas[temp] = element_1;
                Style(1,temp);
                stop = 4;
            }
        }
    if (element_1 == mas[temp])
        {
            stop = 4;
        }
    }while((temp < 15) && (stop != 4));
   stop = 0;
   temp = 0;
}

void MainWindow::Push()
{
    if(mas[min]!=-1)
    {
        Style(1, min);
    }
    if(appex == 0)
    {
       mas[appex]=ui->spinBox->text().toInt(0,10);
       root = mas[appex];
       Style(1,appex);
       ++appex;
    }
    else
    {
       element=ui->spinBox->text().toInt(0,10);
       PUSH(element);
    }
}

void MainWindow::Pop()
{
    if(mas[min]!=-1)
    {
        Style(1, min);
    }
    element=ui->spinBox->text().toInt(0,10);
    for(int wq = 0; wq < 15; wq++)
    {
            if(element == mas[wq])
            {
                if(((mas[left(wq)] == -1) && (mas[right(wq)] == -1)
                    ||
                        (left(wq) > 14) && right(wq) > 14))
                {
                                {
                        mas[wq] = -1;
                        Style(0,wq);
                    }
                 }
                if(((mas[right(wq)] > -1) && (mas[left(wq)] == -1)) || ((mas[left(wq)] > -1)&&(mas[right(wq)] == -1)))
                {
                    mas[wq] = -1;
                     lp = left(wq);
                    rp = right(wq);
                     do
                     {
                         for(int t = lp; t<=rp; t++)
                         {
                             if(mas[t]>-1)
                             {
                                PUSH(mas[t]);
                                Style(0,t);
                                mas[t]=-1;
                }
                         }
                         lp = left(lp);
                         rp = right(rp);

                     }while(lp < 15 && rp < 15);
                }
                if((mas[left(wq)] > -1) && (mas[right(wq)] > -1)) {

                    max = right(wq);

                    while(mas[left(max)] != -1 && left(max)<15)
                    {
                    max = left(max);
                    }
                    if(root==mas[wq])
                    {
                        root = mas[0] = mas[max];
                    }
                        if(mas[right(max)] != -1)
                        {
                            if(root==mas[wq])
                             {
                                 root = mas[0] = mas[max];
                                 label[0]->setText(QString::number(root)); }
                            else
                            {
                                mas[wq] = -1;
                                PUSH(mas[max]); }
                            Style(0,max);
                            mas[max] = -1;
                            lp = left(max);
                            rp = right(max);
                             while(lp < 15 && rp < 15)
                             {
                                 for(int t = lp; t<=rp; t++)
                                 {
                                     if(mas[t]>-1)
                                     {
                                        PUSH(mas[t]);
                                        Style(0,t);
                                        mas[t]=-1;
                                     }
                                 }
                                 lp = left(lp);  rp = right(rp);
                             }
                            break;
                        }
                        if(mas[right(max)] == -1 || right(max)>15)
                        {
                            if(root==mas[wq])
                             {
                                 root = mas[0] = mas[max];
                                 label[0]->setText(QString::number(root));
                             }
                            else
                            {
                                mas[wq] = -1;
                                PUSH(mas[max]);
                            }
                            Style(0,max); mas[max] = -1; break; }
                }
                break; }
    }
}

void MainWindow::Find()
{
    if(mas[min]!=-1)
    { Style(1, min); }
    element_2 = ui->spinBox->text().toInt(0,10);
     for(int li = 0; li < 15; li++)
     {
         if(mas[li] == element_2)
         {
            Style(2, li);
    min = li;
            break;}
     }
}



