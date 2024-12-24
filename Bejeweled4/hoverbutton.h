//
// Created by JOYJinze on 2024/12/12.
//

#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QPushButton>
#include <QSoundEffect>
#include <QCursor>
#include <QLabel>
#include<QPropertyAnimation>

class HoverButton : public QPushButton
{
    Q_OBJECT

public:
    explicit HoverButton(QWidget *parent = nullptr);

    void setImage(QString pathNormal, QString pathHover, int width, int height);
    void setSound(QString pathHover, QString pathLeave, QString pathPress, QString pathRelease);
    void setLabel(QString text, int size);

protected:
    // 重新实现 enterEvent 和 leaveEvent
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void setCircle(int r, int x, int y, int width, int height, QString path, QString path2, QWidget *parent);
     QPropertyAnimation* textAnim = new QPropertyAnimation;

private:
    QIcon iconNormal;
    QIcon iconHover;
    QSoundEffect *soundHover;
    QSoundEffect *soundPress;
    QSoundEffect *soundRelease;
    QSoundEffect *soundLeave;
    QLabel label;
    int w, h;
    int textSize;
};

#endif // HOVERBUTTON_H

