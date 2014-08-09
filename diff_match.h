#ifndef DIFF_MATCH_H
#define DIFF_MATCH_H

#include <QMainWindow>

namespace Ui {
class Diff_Match;
}

class Diff_Match : public QMainWindow
{
    Q_OBJECT

public:
    explicit Diff_Match(QWidget *parent = 0);
    ~Diff_Match();

private slots:
    void on_actionOpen_Left_triggered();

    void on_actionOpen_Right_triggered();

    void on_actionSave_Left_triggered();

    void on_actionSave_Right_triggered();

    void on_pushButtonGenPatch_clicked();

private:
    Ui::Diff_Match *ui;
};

#endif // DIFF_MATCH_H
