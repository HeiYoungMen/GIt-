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
	//=============================��������
	void createActions();
	QAction *openAct;

	//=============================����������
	void createToolBar();
	QToolBar *toolBar;

	//=============================����ͣ������
	void createLeftDock();
	QDockWidget *leftDock;
	QListWidget *fileList;

	//=============================������ͼ
	QGraphicsView *view;
	QGraphicsScene *scene;
	
};
