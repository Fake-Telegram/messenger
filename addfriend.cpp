#include "addfriend.h"

AddFriend::AddFriend(QWidget* pwgt){
    _login = new QLineEdit;
    QLabel *plblLogin = new QLabel("&Login");
    plblLogin->setBuddy(_login);

    QPushButton* pcmdAdd    = new QPushButton("&Add");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");
    QPushButton* pcmdFind   = new QPushButton("&Find");

    connect(pcmdAdd, SIGNAL(clicked()), SLOT());

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblLogin, 0, 0);
    ptopLayout->addWidget(_login, 0, 1);
    ptopLayout->addWidget(pcmdFind, 1, 1);
    ptopLayout->addWidget(pcmdAdd, 2,0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}

QString AddFriend::getLogin(){
    return _login->text();
}
