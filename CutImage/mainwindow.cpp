#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	view = new QGraphicsView(this);
	//设置视窗的滚动条的方针
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	//视窗设置为主窗口的中心部件
	this->setCentralWidget(view);
	//设置主窗口最大化
	setWindowState(windowState() | Qt::WindowMaximized | Qt::WindowActive);
	//设置场景并显示view视窗
	scene = new QGraphicsScene(view);
	view->setScene(scene);
	view->show();
	//设置MyView的背景为实体颜色
	QBrush viewBrush(QColor(0, 0, 255, 150), Qt::SolidPattern);
	view->setBackgroundBrush(viewBrush);
	view->setCacheMode(QGraphicsView::CacheBackground);
	createActions();
	createToolBar();
	createLeftDock();
	
}

void MainWindow::createActions()
{
	openAct = new QAction(QIcon((":/Resources") + tr("/fileopen.png")), tr("打开&O"), this);
	openAct->setShortcut(Qt::Key_Open);
	openAct->setToolTip("打开");
	openAct->setStatusTip("打开图片");
	connect(openAct, SIGNAL(triggered()), this, SLOT(fileOpen()));
}

void MainWindow::createToolBar()
{
	toolBar = this->addToolBar(tr("工具条"));
	toolBar->addAction(openAct);
}

void MainWindow::createLeftDock()
{
	leftDock = new QDockWidget(tr("文件列表"), this, 0);
	this->addDockWidget(Qt::LeftDockWidgetArea, leftDock);
	fileList = new QListWidget();
	leftDock->setWidget(fileList);
	leftDock->show();
}

void MainWindow::fileOpen()
{
	QStringList filePathList = QFileDialog::getOpenFileNames(this, tr("选择图像"), "/home", tr("图像文件(*.bmp *.jpg *.png)"));
	fileShow(filePathList);
}

void MainWindow::fileShow(QStringList filePathList)
{
	fileList->clear();
	fileList->addItems(filePathList);

}