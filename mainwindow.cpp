#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <stdio.h>
#include <time.h>
#include <QAbstractButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    x=0;score=0, r=0;
    ui->setupUi(this);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
          block[i][j]=0; undoblock[i][j]=0;
        }
    }
    num();
    print();






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print(){
    ui->label00->setText((block[0][0]==0)?NULL:(QString::number(block[0][0])));
    ui->label01->setText((block[0][1]==0)?NULL:(QString::number(block[0][1])));
    ui->label02->setText((block[0][2]==0)?NULL:(QString::number(block[0][2])));
    ui->label03->setText((block[0][3]==0)?NULL:(QString::number(block[0][3])));
    ui->label10->setText((block[1][0]==0)?NULL:(QString::number(block[1][0])));
    ui->label11->setText((block[1][1]==0)?NULL:(QString::number(block[1][1])));
    ui->label12->setText((block[1][2]==0)?NULL:(QString::number(block[1][2])));
    ui->label13->setText((block[1][3]==0)?NULL:(QString::number(block[1][3])));
    ui->label20->setText((block[2][0]==0)?NULL:(QString::number(block[2][0])));
    ui->label21->setText((block[2][1]==0)?NULL:(QString::number(block[2][1])));
    ui->label22->setText((block[2][2]==0)?NULL:(QString::number(block[2][2])));
    ui->label23->setText((block[2][3]==0)?NULL:(QString::number(block[2][3])));
    ui->label30->setText((block[3][0]==0)?NULL:(QString::number(block[3][0])));
    ui->label31->setText((block[3][1]==0)?NULL:(QString::number(block[3][1])));
    ui->label32->setText((block[3][2]==0)?NULL:(QString::number(block[3][2])));
    ui->label33->setText((block[3][3]==0)?NULL:(QString::number(block[3][3])));

    ui->label00->setAlignment(Qt::AlignCenter);
    ui->label01->setAlignment(Qt::AlignCenter);
    ui->label02->setAlignment(Qt::AlignCenter);
    ui->label03->setAlignment(Qt::AlignCenter);
    ui->label10->setAlignment(Qt::AlignCenter);
    ui->label11->setAlignment(Qt::AlignCenter);
    ui->label12->setAlignment(Qt::AlignCenter);
    ui->label13->setAlignment(Qt::AlignCenter);
    ui->label20->setAlignment(Qt::AlignCenter);
    ui->label21->setAlignment(Qt::AlignCenter);
    ui->label22->setAlignment(Qt::AlignCenter);
    ui->label23->setAlignment(Qt::AlignCenter);
    ui->label30->setAlignment(Qt::AlignCenter);
    ui->label31->setAlignment(Qt::AlignCenter);
    ui->label32->setAlignment(Qt::AlignCenter);
    ui->label33->setAlignment(Qt::AlignCenter);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        TEST_up();
        if(r==1)
            ui->WIN->setText("");
        print();
        WIN();
        GAMEOVER();

        break;

    case Qt::Key_Down:
        TEST_down();
        if(r==1)
            ui->WIN->setText("");
        print();
        WIN();
        GAMEOVER();
        break;

    case Qt::Key_Right:
        TEST_right();
        if(r==1)
            ui->WIN->setText("");
        print();
        WIN();
        GAMEOVER();
        break;

    case Qt::Key_Left:
        TEST_left();
        if(r==1)
            ui->WIN->setText("");
        print();
        WIN();
        GAMEOVER();
        break;

    default:
        break;
    }
}

void MainWindow::RIGHT()
{
    int i, j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            undoblock[i][j]=block[i][j];
        }
    }

    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(block[i][j]!=0)
            {
                if(block[i][3-x]!=block[i][j])
                {
                    block[i][3-x]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
        for(j=3;j>0;j--)
        {
            if(block[i][j]==block[i][j-1])
            {
                block[i][j]=block[i][j-1]+block[i][j];
                block[i][j-1]=0;
                if(block[i][j]!=0)
                score++;
            }
        }
        for(j=3;j>=0;j--)
        {
            if(block[i][j]!=0)
            {
                if(block[i][3-x]!=block[i][j])
                {
                    block[i][3-x]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
    }
}

void MainWindow::LEFT()
{int i, j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            undoblock[i][j]=block[i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(block[i][j]!=0)
            {
                if(block[i][0+x]!=block[i][j])
                {
                    block[i][0+x]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
        for(j=0;j<3;j++)
        {
            if(block[i][j]==block[i][j+1])
            {
                block[i][j]=block[i][j+1]+block[i][j];
                block[i][j+1]=0;
                if(block[i][j]!=0)
                score++;
            }
        }
        for(j=0;j<4;j++)
        {
            if(block[i][j]!=0)
            {
                if(block[i][0+x]!=block[i][j])
                {
                    block[i][0+x]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
    }
}

void MainWindow::UP()
{
    int i, j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            undoblock[i][j]=block[i][j];
        }
    }
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(block[i][j]!=0)
            {
                if(block[0+x][j]!=block[i][j])
                {
                    block[0+x][j]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
        for(i=0;i<3;i++)
        {
            if(block[i][j]==block[i+1][j])
            {
                block[i][j]=block[i+1][j]+block[i][j];
                block[i+1][j]=0;
                if(block[i][j]!=0)
                score++;
            }
        }
        for(i=0;i<4;i++)
        {
            if(block[i][j]!=0)
            {
                if(block[0+x][j]!=block[i][j])
                {
                    block[0+x][j]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
    }
}
void MainWindow::DOWN()
{int i, j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            undoblock[i][j]=block[i][j];
        }
    }
    for(j=0;j<4;j++)
    {
        for(i=3;i>=0;i--)
        {
            if(block[i][j]!=0)
            {
                if(block[3-x][j]!=block[i][j])
                {
                    block[3-x][j]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
        for(i=3;i>0;i--)
        {
            if(block[i][j]==block[i-1][j])
            {
                block[i][j]=block[i-1][j]+block[i][j];
                block[i-1][j]=0;
                if(block[i][j]!=0)
                score++;
            }
        }
        for(i=3;i>=0;i--)
        {
            if(block[i][j]!=0)
            {
                if(block[3-x][j]!=block[i][j])
                {
                    block[3-x][j]=block[i][j];
                    block[i][j]=0;
                    x++;
                }
                else
                    x++;
            }
        }x=0;
    }
}

void MainWindow::num()
{
    int a, b, c;
    srand(time(NULL));
    a=(rand()%4);
    b=(rand()%4);
    c=(rand()%3)+1;
    while(block[a][b]!=0)
       {
            a=(rand()%4);
            b=(rand()%4);
            c=(rand()%2)+1;
        }

        if(c==1)
            block[a][b]=4;
        else
            block[a][b]=2;
}

void MainWindow::TEST_left()
{
    int test[4][4], i, j, b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            test[i][j]=block[i][j];
        }
    }
    b=0;
        LEFT();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(test[i][j]==block[i][j])
                b++;
            }
        }
        if(b!=16)
        {
            num();
            score++;
            ui->score->setText((score==0)?NULL:(QString::number(score)));
            ui->score->setAlignment(Qt::AlignRight);
        }

}

void MainWindow::TEST_right()
{
    int test[4][4], i, j, b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            test[i][j]=block[i][j];
        }
    }
    b=0;
        RIGHT();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(test[i][j]==block[i][j])
                b++;
            }
        }
        if(b!=16)
        {
            num();
            score++;
            ui->score->setText((score==0)?NULL:(QString::number(score)));
            ui->score->setAlignment(Qt::AlignRight);
        }
}

void MainWindow::TEST_up()
{
    int test[4][4], i, j, b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            test[i][j]=block[i][j];
        }
    }
    b=0;
        UP();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(test[i][j]==block[i][j])
                b++;
            }
        }
        if(b!=16)
        {
            num();
            score++;
            ui->score->setText((score==0)?NULL:(QString::number(score)));
            ui->score->setAlignment(Qt::AlignRight);
        }
}

void MainWindow::TEST_down()
{
    int test[4][4], i, j, b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            test[i][j]=block[i][j];
        }
    }
    b=0;
        DOWN();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(test[i][j]==block[i][j])
                b++;
            }
        }
        if(b!=16)
        {
            num();
            score++;
            ui->score->setText((score==0)?NULL:(QString::number(score)));
            ui->score->setAlignment(Qt::AlignRight);
        }
}

void MainWindow::GAMEOVER()
{
    int test[4][4], i, j,  b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            test[i][j]=block[i][j];
        }
    }
    b=0;
        LEFT();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(test[i][j]==block[i][j])
                b++;
            }
        }
        if(b==16)
        {
            b=0;
            RIGHT();
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(test[i][j]==block[i][j])
                    b++;
                }
            }
            if(b==16)
            {
                b=0;
                UP();
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(test[i][j]==block[i][j])
                        b++;
                    }
                }
                if(b==16)
                {
                    b=0;
                    DOWN();
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(test[i][j]==block[i][j])
                            b++;
                        }
                    }
                    if(b==16)
                    {
                        ui->result->setText("Gameover");
                        ui->result->setAlignment(Qt::AlignCenter);
                    }
                        else
                            for(i=0;i<4;i++)
                            {
                                for(j=0;j<4;j++)
                                {
                                    block[i][j]=test[i][j];
                                }
                            }
                }
                else
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            block[i][j]=test[i][j];
                        }
                    }
            }
            else
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        block[i][j]=test[i][j];
                    }
                }
        }
        else
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    block[i][j]=test[i][j];
                }
            }
}




void MainWindow::setzero()
{
    int i, j;
    //this->PushButton* = true;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                block[i][j]=0;
            }
        }
        num();print();score=0;
        ui->score->setText((score=0)?NULL:(QString::number(score)));
        ui->score->setAlignment(Qt::AlignRight);
        ui->result->setText("");
        ui->result->setAlignment(Qt::AlignCenter);
}
void MainWindow::undo()
{int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            block[i][j]=undoblock[i][j];
        }
    }
    print();
}
void MainWindow::setzero_no()
{
    ui->result->setText("Gameover");
    ui->result->setAlignment(Qt::AlignCenter);
}
void MainWindow::WIN()
{   int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(block[i][j]==2048)
                ui->WIN->setText("WIN!!");
                ui->WIN->setAlignment(Qt::AlignCenter);
                r=1;
        }

    }
}
void MainWindow::AWIN()
{   int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(block[i][j]==2048)
                ui->WIN->setText("WIN!!");
                ui->WIN->setAlignment(Qt::AlignCenter);
        }

    }
    return;
}
void MainWindow::Auto()
{
    int test[4][4], i, j, b;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            test[i][j]=block[i][j];
        }
    }
    b=0;
        RIGHT();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(test[i][j]==block[i][j])
                b++;
            }
        }
        if(b!=16)
        {
            ui->WIN->setText("");
            print();
            WIN();
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    test[i][j]=block[i][j];
                }
            }
            b=0;
                DOWN();
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(test[i][j]==block[i][j])
                        b++;
                    }
                }
                if(b!=16)
                {
                    ui->WIN->setText("");
                    print();
                    AWIN();
                    Auto();
                }
                else
                    Auto();
        }
        else
        {
            ui->WIN->setText("");
            print();
            GAMEOVER();
            DOWN();
            b=0;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(test[i][j]==block[i][j])
                    b++;
                }
            }
            if(b!=16)
            {
                ui->WIN->setText("");
                print();
                AWIN();
                Auto();

            }
            else
            {
                UP();
                b=0;
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(test[i][j]==block[i][j])
                        b++;
                    }
                }
                if(b!=16)
                {
                    ui->WIN->setText("");
                    print();
                    Auto();

                }
                else
                {
                    LEFT();
                    b=0;
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(test[i][j]==block[i][j])
                            b++;
                        }
                    }
                    if(b!=16)
                    {
                        ui->WIN->setText("");
                        print();
                        AWIN();
                        Auto();

                    }
                    else
                        return;
                }
            }


        }

}

