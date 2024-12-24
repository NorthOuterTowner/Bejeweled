//
// Created by JOYJinze on 2024/12/12.
//

#include "hoverbutton.h"
#include <QSoundEffect>
#include <QPixmap>
#include <QFont>
#include <QMouseEvent>
#include <QPropertyAnimation>

HoverButton::HoverButton(QWidget *parent) : QPushButton(parent)
{
    // 设置默认样式
    setStyleSheet("QPushButton{border:0px;}");
    label.setText("");
}

void HoverButton::setImage(QString pathNormal, QString pathHover, int width, int height)
{
    w = width;
    h = height;
    iconNormal = QIcon(QPixmap(pathNormal).scaled(w, h));
    iconHover = QIcon(QPixmap(pathHover).scaled(w, h));

    setIcon(iconNormal);
    setIconSize(QSize(w, h));
}

void HoverButton::setSound(QString pathHover, QString pathLeave, QString pathPress, QString pathRelease)
{
    // 创建音效
    soundHover = new QSoundEffect(this);
    soundHover->setSource(QUrl::fromLocalFile(pathHover));
    soundHover->setVolume(1.0f);

    soundPress = new QSoundEffect(this);
    soundPress->setSource(QUrl::fromLocalFile(pathPress));
    soundPress->setVolume(1.0f);

    soundRelease = new QSoundEffect(this);
    soundRelease->setSource(QUrl::fromLocalFile(pathRelease));
    soundRelease->setVolume(1.0f);

    soundLeave = new QSoundEffect(this);
    soundLeave->setSource(QUrl::fromLocalFile(pathLeave));
    soundLeave->setVolume(1.0f);
}

void HoverButton::setLabel(QString text, int size)
{
    textSize = size;
    label.setText(text);
    label.setParent(this);
    label.setGeometry(0, 0, w, h);
    label.setAlignment(Qt::AlignCenter);
    label.setFont(QFont("Microsoft YaHei", size, QFont::Normal));
    label.setStyleSheet("QLabel{color:pink;}");
    label.setVisible(true);
    // 计算文本的宽度和高度
    QFontMetrics metrics(label.font());
    int textWidth = metrics.horizontalAdvance(label.text());
    int textHeight = metrics.height();

    // 设置按钮大小为文本大小 + 一些额外的间距
    setFixedSize(textWidth + 80 , textHeight + 50);  // 20和10是额外的间距，可以根据需要调整
}

void HoverButton::enterEvent(QEnterEvent *event)
{
    setCursor(QCursor(QPixmap(":/mouse2.png")));  // 鼠标悬停时更改光标
    setIcon(iconHover);  // 鼠标悬停时切换图标
    if (soundHover)
        soundHover->play();  // 播放悬停音效
    if (!label.text().isEmpty()) {
        label.setFont(QFont("Microsoft YaHei", textSize * 1.5, QFont::Bold));
        QFontMetrics metrics(label.font());
        int textWidth = metrics.horizontalAdvance(label.text());
        int textHeight = metrics.height();
        setFixedSize(textWidth + 80, textHeight + 50);  // 自动调整按钮大小
    }

    // 添加动画
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x() - 5, this->y() - 5, this->width() + 10, this->height() + 10));
    animation->start();
    QPushButton::enterEvent(event);
    // 计算文本的宽度和高度
    QFontMetrics metrics(label.font());
    int textWidth = metrics.horizontalAdvance(label.text());
    int textHeight = metrics.height();

    // 设置按钮大小为文本大小 + 一些额外的间距
    setFixedSize(textWidth + 80, textHeight + 50);
}

void HoverButton::leaveEvent(QEvent *event)
{
    setCursor(QCursor(QPixmap(":/mouse1.png")));  // 鼠标离开时恢复光标
    setIcon(iconNormal);  // 恢复图标
    if (soundLeave)
        soundLeave->play();  // 播放离开音效
    if (!label.text().isEmpty()) {
        label.setFont(QFont("Microsoft YaHei", textSize, QFont::Normal));
        QFontMetrics metrics(label.font());
        int textWidth = metrics.horizontalAdvance(label.text());
        int textHeight = metrics.height();
        setFixedSize(textWidth + 20, textHeight + 50);  // 自动调整按钮大小
    }

    // 添加动画
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x() + 5, this->y() + 5, this->width() - 10, this->height() - 10));
    animation->start();
    QPushButton::leaveEvent(event);
    // 计算文本的宽度和高度
    QFontMetrics metrics(label.font());
    int textWidth = metrics.horizontalAdvance(label.text());
    int textHeight = metrics.height();

    // 设置按钮大小为文本大小 + 一些额外的间距
    setFixedSize(textWidth + 80, textHeight + 50);
}

void HoverButton::mousePressEvent(QMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/mouse3.png")));  // 鼠标按下时更改光标
    if (soundPress)
        soundPress->play();  // 播放按下音效
    if (!label.text().isEmpty())
        label.setFont(QFont("Microsoft YaHei", textSize * 1.5, QFont::Bold));

    QPushButton::mousePressEvent(event);
    // 计算文本的宽度和高度
    QFontMetrics metrics(label.font());
    int textWidth = metrics.horizontalAdvance(label.text());
    int textHeight = metrics.height();

    // 设置按钮大小为文本大小 + 一些额外的间距
    setFixedSize(textWidth + 80, textHeight + 50);
}

void HoverButton::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/mouse2.png")));  // 鼠标释放时恢复光标
    if (soundRelease)
        soundRelease->play();  // 播放释放音效
    if (!label.text().isEmpty())
        label.setFont(QFont("Microsoft YaHei", textSize, QFont::Normal));

    QPushButton::mouseReleaseEvent(event);
    // 计算文本的宽度和高度
    QFontMetrics metrics(label.font());
    int textWidth = metrics.horizontalAdvance(label.text());
    int textHeight = metrics.height();

    // 设置按钮大小为文本大小 + 一些额外的间距
    setFixedSize(textWidth + 80, textHeight + 50);
}
void HoverButton::setCircle(int r, int x, int y, int width, int height, QString path, QString path2, QWidget *parent)
{
    setParent(parent);
    setGeometry(x - r, y - r, 2*r, 2*r);
    setImage(path, path2, 2*r, 2*r);
    textAnim->setParent(parent);
    textAnim->setTargetObject(this);
    textAnim->setDuration(2000);
    textAnim->setPropertyName("geometry");
    textAnim->setStartValue(QRect(x - r, height, 2*r, 2*r));
    textAnim->setEndValue(QRect(x - r, y - r, 2*r, 2*r));
    textAnim->setEasingCurve(QEasingCurve::InOutCubic);
    setVisible(false);
}
