#include "Category.h"

Category::Category(QObject *parent)
    : QObject{parent}, sum(0)
{
    // To Get Relative Path for Text Files
    QDir dir;
    dir.cd("../../"); // Return back 2 folders

    // Store path of text files in path
    path = dir.absolutePath();

    // Get values from data base
    Refresh();
}

void Category::startCategory()
{
    // For loop on vector to display items on the List
    for(auto& i : categoryList)
    {

        // Send String to Category List in GUI
        emit sendCategory(i);
    }
}

void Category::Refresh()
{

    categoryList.clear();
    categoryList.resize(0);
    categoryList.shrink_to_fit();

    /******************* Read Category List *******************/
    QFile file(path + QString("//Category.txt"));
    QTextStream ss(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!ss.atEnd())
        {
            QString line = ss.readLine();

            // Add values to the QString
            categoryList << line;
        }
        file.close();
    }
    else
    {
        // Send String to Category List in GUI Saying there was an error & couldn't find the path
        emit sendCategory("Can't open data base file for Category.....");
    }

    /******************* Read Item List of each Category *******************/
    for(auto i = 0; i < categoryList.size(); i++)
    {
        QFile file(path + QString("//") + categoryList[i].split(". ")[1] + QString(".txt"));
        QTextStream ss(&file);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!ss.atEnd())
            {
                QString line = ss.readLine();

                // Add values to the QString
                itemList[categoryList[i]] << line;
            }
            file.close();
        }
        else
        {
            // Send String to Category List in GUI Saying there was an error & couldn't find the path
            emit sendCategory(QString("Can't open data base file for Item %1.....").arg(i));
        }
    }

    //////////////// Initialize Values to Zero ////////////////
    for(auto& i : categoryList)
    {
        for(auto& j : itemList[i])
        {
            numberOfItems[j] = 0;
        }
    }
}

// Print Item list
void Category::displayItemList(QVector<QString> itemList)
{
    // Clear the Item list
    emit clearItem();

    // For loop on vector to display items on the List
    for(auto& i : itemList)
    {

        // Send String to Item List in GUI
        emit sendItem(i);
    }
}

// Receive the selected Category from GUI
void Category::receiveCategorySelected(QString selectedCategory)
{
    // Display the Item List of the selected category
    displayItemList(itemList[selectedCategory]);

    // Display nothing on Line Edit
    emit clearValueLineEdit();
}

// Receive the Value From GUI
void Category::applyValue(QString selectedCategory, QString selectedItem, qint32 value)
{
    // Get the Value of Selected item
    double itemValue = 0;
    QString numberPart;
    for(auto& i : itemList[selectedCategory])
    {
        if(i == selectedItem)
        {
            numberPart = i.split("$")[1];

            if(numberPart.contains("\n"))
            {
                itemValue = numberPart.split("\n")[0].toDouble();
            }
            else
            {
                itemValue = numberPart.toDouble();
            }
        }
    }

    // Remove Old value from the Sum
    sum -= numberOfItems[selectedItem] * itemValue;

    // Update number of Item
    numberOfItems[selectedItem] = value;

    // Update Sum
    sum += numberOfItems[selectedItem]*itemValue;

    // Send Updated Sum value
    emit updateSum(sum);
}

// Receive the selected Item from the GUI
void Category::receiveItemSelected(QString selectedItem)
{

    // Emit Number of this Item in the Cart
    emit numberOfItemInTheCart(numberOfItems[selectedItem]);
}
