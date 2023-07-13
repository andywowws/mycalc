# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'calcer.ui'
##
## Created by: Qt User Interface Compiler version 6.4.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QGridLayout, QLayout, QMainWindow,
    QMenuBar, QPushButton, QSizePolicy, QStatusBar,
    QTextEdit, QWidget)

class Ui_calcer(object):
    def setupUi(self, calcer):
        if not calcer.objectName():
            calcer.setObjectName(u"calcer")
        calcer.setEnabled(True)
        calcer.resize(320, 457)
        self.centralwidget = QWidget(calcer)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayoutWidget = QWidget(self.centralwidget)
        self.gridLayoutWidget.setObjectName(u"gridLayoutWidget")
        self.gridLayoutWidget.setGeometry(QRect(10, 10, 302, 403))
        self.gridLayout = QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setSizeConstraint(QLayout.SetNoConstraint)
        self.gridLayout.setHorizontalSpacing(0)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.pushn9 = QPushButton(self.gridLayoutWidget)
        self.pushn9.setObjectName(u"pushn9")
        self.pushn9.setMinimumSize(QSize(0, 60))
        font = QFont()
        font.setPointSize(15)
        self.pushn9.setFont(font)

        self.gridLayout.addWidget(self.pushn9, 4, 2, 1, 1)

        self.pushjian = QPushButton(self.gridLayoutWidget)
        self.pushjian.setObjectName(u"pushjian")
        self.pushjian.setMinimumSize(QSize(0, 60))
        self.pushjian.setFont(font)

        self.gridLayout.addWidget(self.pushjian, 3, 3, 1, 1)

        self.pushn1 = QPushButton(self.gridLayoutWidget)
        self.pushn1.setObjectName(u"pushn1")
        self.pushn1.setMinimumSize(QSize(0, 60))
        self.pushn1.setFont(font)

        self.gridLayout.addWidget(self.pushn1, 2, 0, 1, 1)

        self.pushjia = QPushButton(self.gridLayoutWidget)
        self.pushjia.setObjectName(u"pushjia")
        self.pushjia.setMinimumSize(QSize(0, 60))
        self.pushjia.setFont(font)

        self.gridLayout.addWidget(self.pushjia, 2, 3, 1, 1)

        self.pushn2 = QPushButton(self.gridLayoutWidget)
        self.pushn2.setObjectName(u"pushn2")
        self.pushn2.setMinimumSize(QSize(0, 60))
        self.pushn2.setFont(font)

        self.gridLayout.addWidget(self.pushn2, 2, 1, 1, 1)

        self.pushn4 = QPushButton(self.gridLayoutWidget)
        self.pushn4.setObjectName(u"pushn4")
        self.pushn4.setMinimumSize(QSize(0, 60))
        self.pushn4.setFont(font)

        self.gridLayout.addWidget(self.pushn4, 3, 0, 1, 1)

        self.pushcheng = QPushButton(self.gridLayoutWidget)
        self.pushcheng.setObjectName(u"pushcheng")
        self.pushcheng.setMinimumSize(QSize(0, 60))
        self.pushcheng.setFont(font)

        self.gridLayout.addWidget(self.pushcheng, 4, 3, 1, 1)

        self.textEdit = QTextEdit(self.gridLayoutWidget)
        self.textEdit.setObjectName(u"textEdit")
        self.textEdit.setMinimumSize(QSize(0, 0))
        self.textEdit.setMaximumSize(QSize(16777215, 71))
        self.textEdit.setFont(font)

        self.gridLayout.addWidget(self.textEdit, 0, 0, 1, 4)

        self.pushn6 = QPushButton(self.gridLayoutWidget)
        self.pushn6.setObjectName(u"pushn6")
        self.pushn6.setMinimumSize(QSize(0, 60))
        self.pushn6.setFont(font)

        self.gridLayout.addWidget(self.pushn6, 3, 2, 1, 1)

        self.pushn7 = QPushButton(self.gridLayoutWidget)
        self.pushn7.setObjectName(u"pushn7")
        self.pushn7.setMinimumSize(QSize(0, 60))
        self.pushn7.setFont(font)

        self.gridLayout.addWidget(self.pushn7, 4, 0, 1, 1)

        self.pushn5 = QPushButton(self.gridLayoutWidget)
        self.pushn5.setObjectName(u"pushn5")
        self.pushn5.setMinimumSize(QSize(0, 60))
        self.pushn5.setFont(font)

        self.gridLayout.addWidget(self.pushn5, 3, 1, 1, 1)

        self.pushchu = QPushButton(self.gridLayoutWidget)
        self.pushchu.setObjectName(u"pushchu")
        self.pushchu.setMinimumSize(QSize(0, 60))
        self.pushchu.setFont(font)

        self.gridLayout.addWidget(self.pushchu, 5, 3, 1, 1)

        self.pushn0 = QPushButton(self.gridLayoutWidget)
        self.pushn0.setObjectName(u"pushn0")
        self.pushn0.setMinimumSize(QSize(0, 60))
        self.pushn0.setFont(font)

        self.gridLayout.addWidget(self.pushn0, 5, 0, 1, 2)

        self.pushn8 = QPushButton(self.gridLayoutWidget)
        self.pushn8.setObjectName(u"pushn8")
        self.pushn8.setMinimumSize(QSize(0, 60))
        self.pushn8.setFont(font)

        self.gridLayout.addWidget(self.pushn8, 4, 1, 1, 1)

        self.pushn3 = QPushButton(self.gridLayoutWidget)
        self.pushn3.setObjectName(u"pushn3")
        self.pushn3.setMinimumSize(QSize(0, 60))
        self.pushn3.setFont(font)

        self.gridLayout.addWidget(self.pushn3, 2, 2, 1, 1)

        self.pushdy = QPushButton(self.gridLayoutWidget)
        self.pushdy.setObjectName(u"pushdy")
        self.pushdy.setMinimumSize(QSize(0, 60))
        self.pushdy.setFont(font)

        self.gridLayout.addWidget(self.pushdy, 5, 2, 1, 1)

        self.pushr = QPushButton(self.gridLayoutWidget)
        self.pushr.setObjectName(u"pushr")
        self.pushr.setMinimumSize(QSize(0, 60))
        self.pushr.setFont(font)

        self.gridLayout.addWidget(self.pushr, 6, 2, 1, 2)

        self.pushl = QPushButton(self.gridLayoutWidget)
        self.pushl.setObjectName(u"pushl")
        self.pushl.setMinimumSize(QSize(0, 60))
        self.pushl.setFont(font)

        self.gridLayout.addWidget(self.pushl, 6, 0, 1, 2)

        calcer.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(calcer)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 320, 22))
        calcer.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(calcer)
        self.statusbar.setObjectName(u"statusbar")
        calcer.setStatusBar(self.statusbar)

        self.retranslateUi(calcer)

        QMetaObject.connectSlotsByName(calcer)
    # setupUi

    def retranslateUi(self, calcer):
        calcer.setWindowTitle(QCoreApplication.translate("calcer", u"\u8ba1\u7b97\u5668", None))
        self.pushn9.setText(QCoreApplication.translate("calcer", u"9", None))
#if QT_CONFIG(shortcut)
        self.pushn9.setShortcut(QCoreApplication.translate("calcer", u"9", None))
#endif // QT_CONFIG(shortcut)
        self.pushjian.setText(QCoreApplication.translate("calcer", u"-", None))
#if QT_CONFIG(shortcut)
        self.pushjian.setShortcut(QCoreApplication.translate("calcer", u"-", None))
#endif // QT_CONFIG(shortcut)
        self.pushn1.setText(QCoreApplication.translate("calcer", u"1", None))
#if QT_CONFIG(shortcut)
        self.pushn1.setShortcut(QCoreApplication.translate("calcer", u"1", None))
#endif // QT_CONFIG(shortcut)
        self.pushjia.setText(QCoreApplication.translate("calcer", u"+", None))
#if QT_CONFIG(shortcut)
        self.pushjia.setShortcut(QCoreApplication.translate("calcer", u"+", None))
#endif // QT_CONFIG(shortcut)
        self.pushn2.setText(QCoreApplication.translate("calcer", u"2", None))
#if QT_CONFIG(shortcut)
        self.pushn2.setShortcut(QCoreApplication.translate("calcer", u"2", None))
#endif // QT_CONFIG(shortcut)
        self.pushn4.setText(QCoreApplication.translate("calcer", u"4", None))
#if QT_CONFIG(shortcut)
        self.pushn4.setShortcut(QCoreApplication.translate("calcer", u"4", None))
#endif // QT_CONFIG(shortcut)
        self.pushcheng.setText(QCoreApplication.translate("calcer", u"\u00d7", None))
#if QT_CONFIG(shortcut)
        self.pushcheng.setShortcut(QCoreApplication.translate("calcer", u"*", None))
#endif // QT_CONFIG(shortcut)
        self.pushn6.setText(QCoreApplication.translate("calcer", u"6", None))
#if QT_CONFIG(shortcut)
        self.pushn6.setShortcut(QCoreApplication.translate("calcer", u"6", None))
#endif // QT_CONFIG(shortcut)
        self.pushn7.setText(QCoreApplication.translate("calcer", u"7", None))
#if QT_CONFIG(shortcut)
        self.pushn7.setShortcut(QCoreApplication.translate("calcer", u"7", None))
#endif // QT_CONFIG(shortcut)
        self.pushn5.setText(QCoreApplication.translate("calcer", u"5", None))
#if QT_CONFIG(shortcut)
        self.pushn5.setShortcut(QCoreApplication.translate("calcer", u"5", None))
#endif // QT_CONFIG(shortcut)
        self.pushchu.setText(QCoreApplication.translate("calcer", u"\u00f7", None))
#if QT_CONFIG(shortcut)
        self.pushchu.setShortcut(QCoreApplication.translate("calcer", u"/", None))
#endif // QT_CONFIG(shortcut)
        self.pushn0.setText(QCoreApplication.translate("calcer", u"0", None))
#if QT_CONFIG(shortcut)
        self.pushn0.setShortcut(QCoreApplication.translate("calcer", u"0", None))
#endif // QT_CONFIG(shortcut)
        self.pushn8.setText(QCoreApplication.translate("calcer", u"8", None))
#if QT_CONFIG(shortcut)
        self.pushn8.setShortcut(QCoreApplication.translate("calcer", u"8", None))
#endif // QT_CONFIG(shortcut)
        self.pushn3.setText(QCoreApplication.translate("calcer", u"3", None))
#if QT_CONFIG(shortcut)
        self.pushn3.setShortcut(QCoreApplication.translate("calcer", u"3", None))
#endif // QT_CONFIG(shortcut)
        self.pushdy.setText(QCoreApplication.translate("calcer", u"=", None))
#if QT_CONFIG(shortcut)
        self.pushdy.setShortcut(QCoreApplication.translate("calcer", u"Return", None))
#endif // QT_CONFIG(shortcut)
        self.pushr.setText(QCoreApplication.translate("calcer", u")", None))
#if QT_CONFIG(shortcut)
        self.pushr.setShortcut(QCoreApplication.translate("calcer", u")", None))
#endif // QT_CONFIG(shortcut)
        self.pushl.setText(QCoreApplication.translate("calcer", u"(", None))
#if QT_CONFIG(shortcut)
        self.pushl.setShortcut(QCoreApplication.translate("calcer", u"(", None))
#endif // QT_CONFIG(shortcut)
    # retranslateUi

