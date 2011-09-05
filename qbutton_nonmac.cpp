/*
Copyright (C) 2011 by Mike McQuaid

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "qbutton.h"

#include <QPushButton>
#include <QVBoxLayout>

class QButtonPrivate
{
public:
    QButtonPrivate(QPushButton *pushButton) : pushButton(pushButton) {}
    QPushButton *pushButton;
};

QButton::QButton(QWidget *parent, BezelStyle) : QWidget(parent)
{
    QPushButton *pushButton = new QPushButton(this);
    connect(pushButton, SIGNAL(clicked()),
            this, SIGNAL(clicked()));
    pimpl = new QButtonPrivate(pushButton);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(pushButton);
}

void QButton::setText(const QString &text)
{
    pimpl->pushButton->setText(text);
}