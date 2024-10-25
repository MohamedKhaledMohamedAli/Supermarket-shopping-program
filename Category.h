#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QTextStream>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QDir>

class Category : public QObject
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = nullptr);

    // Start the Category Class
    void startCategory(void);

    // Print Item list
    void displayItemList(QVector<QString> itemList);

signals:

    // Signal to send Category from the file to GUI (Supermarket Class)
    void sendCategory(QString category);

    // Signal to Clear Category List widget in GUI
    void clearCategory(void);

    // Send Value to be displayed on Line Edit
    void sendValueLineEdit(qint32 val);

    // Display nothing on Line Edit
    void clearValueLineEdit(void);

    // Signal to send Items from the file to GUI (Supermarket Class)
    void sendItem(QString item);

    // Signal to Clear Item List widget in GUI
    void clearItem(void);

    // Send Updated Sum value to GUI
    void updateSum(double value);

    // Emit Number of this Item in the Cart to the GUI
    void numberOfItemInTheCart(qint32 number);

public slots:

    // Receive the selected Category from GUI
    void receiveCategorySelected(QString selectedCategory);

    // Receive the Value From GUI
    void applyValue(QString selectedCategory, QString selectedItem, qint32 value);

    // Receive the selected Item from the GUI
    void receiveItemSelected(QString selectedItem);

private:
    void Refresh();
    QString path;
    QVector<QString> categoryList;
    QMap<QString, QVector<QString>> itemList;
    QMap<QString, qint32> numberOfItems;
    double sum;
};

#endif // CATEGORY_H
