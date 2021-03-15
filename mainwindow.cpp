#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include "gamehandler.h"

using namespace std;

int iSecret;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_InitialsButton_clicked()
{
    GameHandler gamer;

    string init = this->ui->InitialsTextBox->toPlainText().toStdString();
    gamer.setInitials(init);

    QString qstr = QString::fromStdString(gamer.getInitials());
    this->ui->CurrentInitials->setText(qstr);

    this->ui->GuessPushButton->setEnabled(true);
    this->ui->GuessBox->setEnabled(true);
    iSecret = rand() % 12 + 1;

}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}





void MainWindow::on_GuessPushButton_clicked()
{

    GameHandler gamer;
    string guess;

    this->ui->LABELGuessFeedback->setText("Please enter your guess. If you would like a hint, type 'hint' ");


            //if number is between 1-12 run

            do {
                //if true then private array
                gamer.hide(true, iSecret);

                guess = this->ui->GuessBox->toPlainText().toStdString();
                if (guess == "hint") {

                    string hint = gamer.displayHint();
                    QString qstr = QString::fromStdString(hint);
                    this->ui->WordIs->setText(qstr);

                }

                else {
                    //check if users guess was valid
                    guess = guess.substr(0, 1);
                    gamer.checkGuess(guess);
                }

                this->ui->GuessBox->clear();
            } while (gamer.gameState());

            this->ui->GameWinOrLose->setText("Test");

            string position = gamer.display(true, iSecret);
            QString qstr = QString::fromStdString(position);

            this->ui->WordIs->setText(qstr);

}
