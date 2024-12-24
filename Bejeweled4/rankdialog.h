#ifndef RANKDIALOG_H
#define RANKDIALOG_H

#include <QDialog>

namespace Ui {
class RankDialog;
}

class RankDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RankDialog(QWidget *parent = nullptr);
     Ui::RankDialog *ui;
    ~RankDialog();

 private slots:
     void on_pushButton_clicked();

 private:

};

#endif // RANKDIALOG_H
