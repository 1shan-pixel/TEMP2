#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    player->setAudioOutput(audio);

    connect (player, &QMediaPlayer::positionChanged, this, &Dialog:: on_positionChanged);
    connect (player, &QMediaPlayer::durationChanged, this, &Dialog:: on_durationChanged);

}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog:: on_StartButton_clicked()
{
    // load and play the file
    player->setSource(QUrl::fromLocalFile("qrc:/songs/moonlight.mp3"));

    player->play();

    qDebug()<< player->errorString();


}




void Dialog::on_StopButton_clicked()
{
    player->stop();

}

void Dialog:: on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
}
void Dialog:: on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}


void Dialog::on_sliderVolume_sliderMoved(int position)
{
    audio->setVolume(position);

}


void Dialog::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

