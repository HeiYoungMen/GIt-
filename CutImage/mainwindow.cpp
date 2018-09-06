#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	view = new QGraphicsView(this);
	//�����Ӵ��Ĺ������ķ���
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	//�Ӵ�����Ϊ�����ڵ����Ĳ���
	this->setCentralWidget(view);
	//�������������
	setWindowState(windowState() | Qt::WindowMaximized | Qt::WindowActive);
	//���ó�������ʾview�Ӵ�
	scene = new QGraphicsScene(view);
	view->setScene(scene);
	view->show();
	//����MyView�ı���Ϊʵ����ɫ
	QBrush viewBrush(QColor(0, 0, 255, 150), Qt::SolidPattern);
	view->setBackgroundBrush(viewBrush);
	view->setCacheMode(QGraphicsView::CacheBackground);
	createActions();
	createToolBar();
	createLeftDock();
	
}

void MainWindow::createActions()
{
	openAct = new QAction(QIcon((":/Resources") + tr("/fileopen.png")), tr("��&O"), this);
	openAct->setShortcut(Qt::Key_Open);
	openAct->setToolTip("��");
	openAct->setStatusTip("��ͼƬ");
	connect(openAct, SIGNAL(triggered()), this, SLOT(fileOpen()));
}

void MainWindow::createToolBar()
{
	toolBar = this->addToolBar(tr("������"));
	toolBar->addAction(openAct);
}

void MainWindow::createLeftDock()
{
	leftDock = new QDockWidget(tr("�ļ��б�"), this, 0);
	this->addDockWidget(Qt::LeftDockWidgetArea, leftDock);
	fileList = new QListWidget();
	leftDock->setWidget(fileList);
	leftDock->show();
}

void MainWindow::fileOpen()
{
	QStringList filePathList = QFileDialog::getOpenFileNames(this, tr("ѡ��ͼ��"), "/home", tr("ͼ���ļ�(*.bmp *.jpg *.png)"));
	fileShow(filePathList);
}

void MainWindow::fileShow(QStringList filePathList)
{
	fileList->clear();
	fileList->addItems(filePathList);

}