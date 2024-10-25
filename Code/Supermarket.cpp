#include "Supermarket.h"
#include "ui_Supermarket.h"

Supermarket::Supermarket(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Supermarket), flag_a_Category_is_selected(false), flag_an_item_is_selected(false)
{
    ui->setupUi(this);

    // Create object of category class on the heap
    category = new Category();

    // connect(thread,&QThread::started,worker,&Worker::doWork);
    /*** Connect signals of Category Class with slots in GUI ***/
    connect(category,&Category::sendCategory,this,&Supermarket::adjustCategoryList);
    connect(category,&Category::clearCategory,this,&Supermarket::clearCategoryList);
    connect(category,&Category::sendValueLineEdit,this,&Supermarket::setValueOnLineEdit);
    connect(category,&Category::clearValueLineEdit,this,&Supermarket::clearValueOnLineEdit);
    connect(category,&Category::sendItem,this,&Supermarket::adjustItemList);
    connect(category,&Category::clearItem,this,&Supermarket::clearItemList);
    connect(category,&Category::updateSum,this,&Supermarket::updateSum);
    connect(category,&Category::numberOfItemInTheCart,this,&Supermarket::numberOfItemInTheCart);

    /*** Connect signals of GUI with slots of Category Class ***/
    connect(this,&Supermarket::sendCategorySelected,category,&Category::receiveCategorySelected);
    connect(this,&Supermarket::sendItemSelected,category,&Category::receiveItemSelected);
    connect(this,&Supermarket::applyValue,category,&Category::applyValue);

    // Start the Category List
    category->startCategory();
}

// Used to Adjust the Category List
void Supermarket::adjustCategoryList(QString category)
{

    // Add category string to Category List
    ui->CategoryList->addItem(category);
}

// Clear the Category List
void Supermarket::clearCategoryList()
{
    // Clear the Category List
    ui->CategoryList->clear();
}

// Display value sent from Category Class
void Supermarket::setValueOnLineEdit(qint32 value)
{

    // Display Value on Quantity Line Edit
    ui->QuantiyInput->clear();
    ui->QuantiyInput->insert(QString::number(value));
}

void Supermarket::clearValueOnLineEdit(void)
{

    // Clear Quality Line Edit
    ui->QuantiyInput->clear();
}

// Used to Adjust the Item List
void Supermarket::adjustItemList(QString item)
{

    // Add items to the list
    ui->itemList->addItem(item);
}

// Clear the Item List
void Supermarket::clearItemList()
{

    // Clear the Item List
    ui->itemList->clear();
}

// Get Updated Sum value from Category Class
void Supermarket::updateSum(double value)
{

    // Display value on Sum LCD
    ui->SumNumber->display(QString::number(value));
}

// Recieve Number of this Item in the Cart from Category Class
void Supermarket::numberOfItemInTheCart(qint32 number)
{

    // Display number of Items on Line Edit
    ui->QuantiyInput->clear();
    ui->QuantiyInput->insert(QString::number(number));
}

Supermarket::~Supermarket()
{
    delete ui;
}

void Supermarket::on_CategoryList_itemPressed(QListWidgetItem *item)
{

    // Send the selected Category to the Category Class
    emit sendCategorySelected(item->text());

    // Set Flag of Category to True
    flag_a_Category_is_selected = true;

    // Set Flag of Item to False
    flag_an_item_is_selected = false;
}


void Supermarket::on_ApplyButtom_pressed()
{

    // If both Category and Item is selected
    if(flag_an_item_is_selected && flag_a_Category_is_selected)
    {
        if((ui->QuantiyInput->text().toInt() >= 0) && (ui->QuantiyInput->text().toInt() <= 99))
        {
            // Send the Value To Category Class
            emit applyValue(ui->CategoryList->currentItem()->text(), ui->itemList->currentItem()->text(), ui->QuantiyInput->text().toInt());
        }
    }
}


void Supermarket::on_itemList_itemClicked(QListWidgetItem *item)
{

    // Send the selected Item to the Category Class
    emit sendItemSelected(item->text());

    // Set Flag of Item to False
    flag_an_item_is_selected = true;
}

