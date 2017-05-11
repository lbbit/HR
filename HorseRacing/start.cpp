#include "start.h"
#include "ui_start.h"
#include <QFile>
#include <QDataStream>
#include "globalvariable.h"
#include <QTextStream>

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    this->setFocus();
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPixmap bgImages(":/BG/src/BG0.png");
    QPalette this_palette = this->palette();
    this_palette.setBrush(QPalette::Window,QBrush(bgImages));
    this->setPalette(this_palette);
    ui->pushButton_start->setFocus();
    ui->pushButton_start->setShortcut( QKeySequence::InsertParagraphSeparator );  //设置快捷键为键盘的“回车”键
    ui->pushButton_start->setShortcut(Qt::Key_Enter);  //设置快捷键为enter键
    ui->pushButton_start->setShortcut(Qt::Key_Return); //设置快捷键为小键盘上的enter键
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_start_clicked()
{
    bee.play();
    emit resetBG(1);
    emit display(1);
    this->setFocus();
}


void Start::on_pushButton_exit_clicked()
{
    bee.play();
    //输出日志
    QFile logtemp("HR_log.txt");
    logtemp.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream out_log(&logtemp);
    out_log<<dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"： "+
             "退出游戏...\n";
    logtemp.close();
    exit(0);
}

void Start::on_pushButton_left_clicked()
{
    bee.play();
}

void Start::on_pushButton_clicked()
{
    bee.play();
    ad.show();
}
