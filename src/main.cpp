#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QList>
#include <QHeaderView>

class MainView : public QWidget {
    public:
        MainView(QWidget* parent = 0);

    private:
        QLabel* actions_label;
        QPushButton* done_button;
        QPushButton* delete_button;

        QTableWidget* table;
};

QTableWidgetItem* newQTableWidgetItem(const std::string& value){
    QTableWidgetItem* item = new QTableWidgetItem();
    QString q_value = value.c_str();
    item->setText(q_value);
    return item;
}

void add_row(QTableWidget* table, const std::string& id, const std::string& project, const std::string& priority, const std::string& age, const std::string& description){
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, newQTableWidgetItem(id));
    table->setItem(row, 1, newQTableWidgetItem(project));
    table->setItem(row, 2, newQTableWidgetItem(priority));
    table->setItem(row, 3, newQTableWidgetItem(age));
    table->setItem(row, 4, newQTableWidgetItem(description));
}

MainView::MainView(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox = new QHBoxLayout();

    actions_label = new QLabel("Actions: ", this);

    done_button = new QPushButton("Done", this);
    delete_button = new QPushButton("Delete", this);

    hbox->addWidget(actions_label, 0, Qt::AlignLeft);
    hbox->addWidget(done_button, 0, Qt::AlignLeft);
    hbox->addWidget(delete_button, 1, Qt::AlignLeft);

    QStringList headers;
    headers << "ID" << "Project" << "Priority" << "Age" << "Description";

    table = new QTableWidget(this);
    table->setColumnCount(5);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    table->setHorizontalHeaderLabels(headers);

    add_row(table, "2", "appart", "H", "1mo", "Caca1");
    add_row(table, "1", "books", "M", "1d", "Caca2");
    add_row(table, "3", "appart", "L", "1w", "Caca3");
    
    vbox->addLayout(hbox);
    vbox->addWidget(table);
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    MainView window;

    window.resize(600, 400);
    window.setWindowTitle("TaskManager");
    window.show();

    return app.exec();
}
