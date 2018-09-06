#pragma once

#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QToolBar>
#include <QDockWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QListWidget>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	
private slots:
	void fileOpen();
	void fileShow(QStringList filePathList);

private:
	//=============================创建动作
	void createActions();
	QAction *openAct;

	//=============================创建工具条
	void createToolBar();
	QToolBar *toolBar;

	//=============================创建停靠窗口
	void createLeftDock();
	QDockWidget *leftDock;
	QListWidget *fileList;

	//=============================创建视图
	QGraphicsView *view;
	QGraphicsScene *scene;
	
};
