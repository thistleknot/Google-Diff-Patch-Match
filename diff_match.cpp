#include "diff_match.h"
#include "ui_diff_match.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include <QtCore>
#include <QString>
#include <QList>
#include <QMap>
#include <QVariant>
#include "diff_match_patch.h"

Diff_Match::Diff_Match(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Diff_Match)
{
    ui->setupUi(this);
}

Diff_Match::~Diff_Match()
{
    delete ui;
}

void Diff_Match::on_actionOpen_Left_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEditLeft->setText(in.readAll());
        file.close();
    }
}

void Diff_Match::on_actionOpen_Right_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEditRight->setText(in.readAll());
        file.close();
    }
}

void Diff_Match::on_actionSave_Left_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << ui->textEditLeft->toPlainText();
            stream.flush();
            file.close();
        }
    }
}

void Diff_Match::on_actionSave_Right_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << ui->textEditRight->toPlainText();
            stream.flush();
            file.close();
        }
    }
}

void Diff_Match::on_pushButtonGenPatch_clicked()
{
  diff_match_patch dmp;
  QString str1 = QString("First string in diff");
  QString str2 = QString("Second string in diff");

  QString strPatch = dmp.patch_toText(dmp.patch_make(str1, str2));
  QPair<QString, QVector<bool> > out
      = dmp.patch_apply(dmp.patch_fromText(strPatch), str1);
  QString strResult = out.first;

  // here, strResult will equal str2 above.
  //return 0;

}
