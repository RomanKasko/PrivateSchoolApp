#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class Adminpage;
}

class Adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit Adminpage(QWidget *parent = nullptr);
    ~Adminpage();

private:
    Ui::Adminpage *ui;
};

#endif // ADMINPAGE_H
