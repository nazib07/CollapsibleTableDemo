#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include <QStandardItemModel>


#include <qadvancedheaderview.h>
#include <qconditionaldecorationdialog.h>
#include <qconditionaldecorationproxymodel.h>
#include <qfiltermodel.h>
#include <qfiltermodelproxy.h>
#include <qfilterviewconnector.h>
#include <qgroupingproxymodel.h>
#include <qconditionaldecoration.h>
#include <qfixedrowstableview.h>
#include <qmimedatautil.h>
#include <qrangefilter.h>
#include <quniquevaluesproxymodel.h>
#include <qselectionlistfilter.h>
#include <qtablemodelwriter.h>
#include <qtextfilter.h>
#include <qvaluefilter.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
Q_OBJECT

public:
explicit Form(QWidget *parent = nullptr);
~Form();
void initModel();
private:
Ui::Form *ui;

QStandardItemModel* m_model;
QGroupingProxyModel* m_groupingProxy;
};

#endif // FORM_H
