#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
                              QWidget(parent),
                              ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog);

    initModel();

    ui->groupingTreeView->setHeader(new QAdvancedHeaderView(Qt::Horizontal, ui->groupingTreeView));

    m_groupingProxy = new QGroupingProxyModel(this);
    m_groupingProxy->setModelColumn(2);
    m_groupingProxy->addGroup(QIcon(":/icons/folder"), "general software development");
    m_groupingProxy->addGroup(QIcon(":/icons/folder"), "Qt's Tools", "Qt's tools");
    m_groupingProxy->setSourceModel(m_model);

    m_groupingProxy->setData(m_groupingProxy->index(0, 0), QIcon(":/icons/folder"), Qt::DecorationRole);

    QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(m_groupingProxy);
    //
    ui->groupingTreeView->setModel(m_groupingProxy);
}

Form::~Form()
{
    delete ui;
}


void Form::initModel()
{
    bool singleRow = false;
    if (singleRow){
        m_model = new QStandardItemModel(1, 12, this);
    } else {
        m_model = new QStandardItemModel(26, 12, this);
    }

    m_model->setHeaderData(0, Qt::Horizontal, tr("Int"));
    m_model->setHeaderData(1, Qt::Horizontal, tr("Qt"));
    m_model->setHeaderData(2, Qt::Horizontal, tr("Qt Group"));
    m_model->setHeaderData(3, Qt::Horizontal, tr("Maturity Level"));
    m_model->setHeaderData(4, Qt::Horizontal, tr("Char (UC)"));
    m_model->setHeaderData(5, Qt::Horizontal, tr("Char (LC)"));
    m_model->setHeaderData(6, Qt::Horizontal, tr("Time"));
    m_model->setHeaderData(7, Qt::Horizontal, tr("Date & Time"));
    m_model->setHeaderData(8, Qt::Horizontal, tr("Duplicate Values"));
    m_model->setHeaderData(9, Qt::Horizontal, tr("Release Date"));
    m_model->setHeaderData(10, Qt::Horizontal, tr("Qt Versions"));
    m_model->setHeaderData(11, Qt::Horizontal, tr("OS"));

    if (singleRow){
        m_model->setData(m_model->index(0, 0), 1);
        m_model->setData(m_model->index(0, 4), QChar(65));
        m_model->setData(m_model->index(0, 5), QChar(97));
        m_model->setData(m_model->index(0, 6), QTime::currentTime());
        m_model->setData(m_model->index(0, 7), QDateTime::currentDateTime());
    } else {
        for(int iRows = 0; iRows < m_model->rowCount(); iRows++){
            m_model->setData(m_model->index(iRows, 0), iRows + 1);
            m_model->setData(m_model->index(iRows, 4), QChar(65 + iRows));
            m_model->setData(m_model->index(iRows, 5), QChar(97 + iRows));
            m_model->setData(m_model->index(iRows, 6), QTime::currentTime().addSecs(iRows * 10));
            m_model->setData(m_model->index(iRows, 7), QDateTime::currentDateTime().addDays(iRows));
        }

        for(int iRows = 0; iRows < m_model->rowCount(); iRows += 2){
            m_model->setData(m_model->index(iRows, 8), QChar(65 + iRows));
            m_model->setData(m_model->index(iRows + 1, 8), QChar(65 + iRows));
        }
    }
    m_model->setData(m_model->index(0, 1), "QtCore");
    m_model->setData(m_model->index(0, 2), "general software development");
    m_model->setData(m_model->index(0, 3), "Active");

    if (!singleRow){
        m_model->setData(m_model->index(1, 1), "QtGui");
        m_model->setData(m_model->index(1, 2), "general software development");
        m_model->setData(m_model->index(1, 3), "Active");

        m_model->setData(m_model->index(2 ,1), "QtMultimedia");
        m_model->setData(m_model->index(2, 2), "general software development");
        m_model->setData(m_model->index(2, 3), "Deprecated");

        m_model->setData(m_model->index(3, 1), "QtNetwork");
        m_model->setData(m_model->index(3, 2), "general software development");
        m_model->setData(m_model->index(3, 3), "Active");

        m_model->setData(m_model->index(4, 1), "QtOpenGL");
        m_model->setData(m_model->index(4, 2), "general software development");
        m_model->setData(m_model->index(4, 3), "Maintained");

        m_model->setData(m_model->index(5, 1), "QtOpenVG");
        m_model->setData(m_model->index(5, 2), "general software development");
        m_model->setData(m_model->index(6, 1), "QtScript");
        m_model->setData(m_model->index(6, 2), "general software development");
        m_model->setData(m_model->index(6, 3), "Active");

        m_model->setData(m_model->index(7, 1), "QtScriptTools");
        m_model->setData(m_model->index(7, 2), "general software development");
        m_model->setData(m_model->index(8, 1), "QtSql");
        m_model->setData(m_model->index(8, 3), "Done");

        m_model->setData(m_model->index(8, 2), "general software development");
        m_model->setData(m_model->index(9, 1), "QtSvg");
        m_model->setData(m_model->index(9, 2), "general software development");
        m_model->setData(m_model->index(9, 3), "Deprecated");

        m_model->setData(m_model->index(10, 1), "QtWebKit");
        m_model->setData(m_model->index(10, 2), "general software development");
        m_model->setData(m_model->index(10, 3), "Active");

        m_model->setData(m_model->index(11, 1), "QtXml");
        m_model->setData(m_model->index(11, 2), "general software development");
        m_model->setData(m_model->index(11, 3), "Done");

        m_model->setData(m_model->index(12, 1), "QtXmlPatterns");
        m_model->setData(m_model->index(12, 2), "general software development");
        m_model->setData(m_model->index(12, 3), "Done");

        m_model->setData(m_model->index(13, 1), "QtDeclarative");
        m_model->setData(m_model->index(13, 2), "general software development");
        m_model->setData(m_model->index(14, 1), "Phonon");
        m_model->setData(m_model->index(14, 2), "general software development");

        m_model->setData(m_model->index(15, 1), "Qt3Support");
        m_model->setData(m_model->index(15, 2), "general software development");
        m_model->setData(m_model->index(15, 3), "Deprecated");

        m_model->setData(m_model->index(16, 1), "QtDesigner");
        m_model->setData(m_model->index(16, 2), "Qt's tools");
        m_model->setData(m_model->index(16, 3), "Done");

        m_model->setData(m_model->index(17, 1), "QtUiTools");
        m_model->setData(m_model->index(17, 2), "Qt's tools");
        m_model->setData(m_model->index(18, 1), "QtHelp");
        m_model->setData(m_model->index(18, 2), "Qt's tools");
        m_model->setData(m_model->index(19, 1), "QtTest");
        m_model->setData(m_model->index(19, 2), "Qt's tools");
        m_model->setData(m_model->index(20, 1), "QAxContainer");
        m_model->setData(m_model->index(20, 2), "Windows developers");
        m_model->setData(m_model->index(21, 1), "QAxServer");
        m_model->setData(m_model->index(21, 2), "Windows developers");
        m_model->setData(m_model->index(21, 1), "QtDBus");
        m_model->setData(m_model->index(21, 2), "Unix developers");
        m_model->setData(m_model->index(22, 1), "C++");
        m_model->setData(m_model->index(23, 1), "JavaScript");
    }

    m_model->setData(m_model->index(0, 9), QDate(1998, 7, 10));
    m_model->setData(m_model->index(0, 10), "1.40");

    if (!singleRow){
        m_model->setData(m_model->index(1, 9), QDate(1998, 10, 2));
        m_model->setData(m_model->index(1, 10), "1.41");

        m_model->setData(m_model->index(2, 9), QDate(1998, 12, 19));
        m_model->setData(m_model->index(2, 10), "1.42");

        m_model->setData(m_model->index(3, 9), QDate(1999, 3, 13));
        m_model->setData(m_model->index(3, 10), "1.44");

        m_model->setData(m_model->index(4, 9), QDate(1999, 6, 26));
        m_model->setData(m_model->index(4, 10), "2.0");

        m_model->setData(m_model->index(5, 9), QDate(2000, 4, 13));
        m_model->setData(m_model->index(5, 10), "2.1");

        m_model->setData(m_model->index(6, 9), QDate(2000, 12, 7));
        m_model->setData(m_model->index(6, 10), "2.2");

        m_model->setData(m_model->index(7, 9), QDate(2001, 3, 8));
        m_model->setData(m_model->index(7, 10), "2.3");

        m_model->setData(m_model->index(8, 9), QDate(2001, 10, 16));
        m_model->setData(m_model->index(8, 10), "3");

        m_model->setData(m_model->index(9, 9), QDate(2001, 11, 14));
        m_model->setData(m_model->index(9, 10), "3.1");

        m_model->setData(m_model->index(10, 9), QDate(2003, 7, 24));
        m_model->setData(m_model->index(10, 10), "3.2");

        m_model->setData(m_model->index(11, 9), QDate(2004, 2, 5));
        m_model->setData(m_model->index(11, 10), "3.3");

        m_model->setData(m_model->index(12, 9), QDate(2005, 12, 20));
        m_model->setData(m_model->index(12, 10), "4.1");

        m_model->setData(m_model->index(13, 9), QDate(2006, 10, 4));
        m_model->setData(m_model->index(13, 10), "4.2");

        m_model->setData(m_model->index(14, 9), QDate(2007, 5, 30));
        m_model->setData(m_model->index(14, 10), "4.3");

        m_model->setData(m_model->index(15, 9), QDate(2008, 5, 6));
        m_model->setData(m_model->index(15, 10), "4.4");

        m_model->setData(m_model->index(16, 9), QDate(2009, 3, 3));
        m_model->setData(m_model->index(16, 10), "4.5");

        m_model->setData(m_model->index(17, 9), QDate(2009, 12, 1));
        m_model->setData(m_model->index(17, 10), "4.6.0");

        m_model->setData(m_model->index(18, 9), QDate(2010, 9, 21));
        m_model->setData(m_model->index(18, 10), "4.7");

        m_model->setData(m_model->index(19, 9), QDate(2010, 11, 9));
        m_model->setData(m_model->index(19, 10), "4.7.1");

        m_model->setData(m_model->index(20, 9), QDate(2011, 3, 1));
        m_model->setData(m_model->index(20, 10), "4.7.2");

        m_model->setData(m_model->index(21, 9), QDate(2011, 5, 4));
        m_model->setData(m_model->index(21, 10), "4.7.3");

        m_model->setData(m_model->index(22, 9), QDate(2011, 9, 1));
        m_model->setData(m_model->index(22, 10), "4.7.4");

        m_model->setData(m_model->index(23, 9), QDate(2011, 12, 15));
        m_model->setData(m_model->index(23, 10), "4.8");
    }
    // Columns OS
    m_model->setData(m_model->index(0, 11), "Windows");
    if (!singleRow){
        m_model->setData(m_model->index(1, 11), "Windows CE");
        m_model->setData(m_model->index(2, 11), "Mac OS X");
        m_model->setData(m_model->index(3, 11), "Linux");
        m_model->setData(m_model->index(4, 11), "Embedded Linux");
    }
}
