#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Hard.h"
#include <QTimer>
#include "windns.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPixmap m_GridPixmap;
    QTimer colletdata;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void DrawWave();
   void DrawGrid(HDC hDC,QRect Rect);
   void DrawWaveInYT(HDC hDC,QRect Rect,USHORT nCH);
    Hard hard;
private:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);
    QPaintEngine * paintEngine() const { return 0; }

private:
    Ui::MainWindow *ui;
public slots:
    void timeout();
};

#endif // MAINWINDOW_H
