#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <QMainWindow>
#include <QListWidget>
#include <Category.h>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui {
class Supermarket;
}
QT_END_NAMESPACE

class Supermarket : public QMainWindow
{
    Q_OBJECT

public:
    Supermarket(QWidget *parent = nullptr);


    ~Supermarket();

public slots:
    // Used to Adjust the Category List
    void adjustCategoryList(QString category);

    // Clear the Category List
    void clearCategoryList(void);

    // Display value sent from Category Class
    void setValueOnLineEdit(qint32 value);

    // Clear Display value
    void clearValueOnLineEdit(void);

    // Used to Adjust the Item List
    void adjustItemList(QString item);

    // Clear the Item List
    void clearItemList(void);

    // Get Updated Sum value from Category Class
    void updateSum(double value);

    // Recieve Number of this Item in the Cart from Category Class
    void numberOfItemInTheCart(qint32 number);

private slots:
    void on_CategoryList_itemPressed(QListWidgetItem *item);

    void on_ApplyButtom_pressed();

    void on_itemList_itemClicked(QListWidgetItem *item);

signals:

    // Send the selected Category to the Category Class
    void sendCategorySelected(QString selectedCategory);

    // Send the Value To Category Class
    void applyValue(QString selectedCategory, QString selectedItem, qint32 value);

    // Send the selected Item to the Category Class
    void sendItemSelected(QString selectedItem);

private:
    Ui::Supermarket *ui;

    // Creat pointer of Class Category
    Category  *category;

    bool flag_a_Category_is_selected;
    bool flag_an_item_is_selected;

};
#endif // SUPERMARKET_H
