#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QMediaPlayer>
#include<QDebug>
#include<QAudioOutput>



QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_StartButton_clicked();

    void on_sliderVolume_sliderMoved(int position);

    void on_sliderProgress_sliderMoved(int position);

    void on_StopButton_clicked();

    void on_durationChanged(qint64 position);
    void on_positionChanged(qint64 position);
private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
    QAudioOutput* audio;

};
#endif // DIALOG_H
