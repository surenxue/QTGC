#include <QApplication>
#include <QLabel>//标签头文件 

#include <QLineEdit>
#include <QPushButton>//按钮头文件 
#include <QHBoxLayout>//水平布局
#include <QVBoxLayout>//垂直布局

#include <QWig>
int main(int argc,char *argc[]) {
	QApplication app(argc,argv);
	
	QLabel *infoLabel  = new QLabel;
	QLabel *openLabel  = new QLabel;
	
	QLineEdit *cmdLineEdit = new QLinEdit;
	
	QPushButton *commitButton= new QPushButton;
	QPushButton *cancelButton= new QPushButton;
	OPushButton *browseButton = new OPushButton:
	
	
	infoLabel-> setText("input cmd");//标签1
	openLabel-> setText("open");//标签2
	
	commitButton-> setText("commit");//确定
	cancelButton-> setText("cancel");//取消
	browseButton-> setText("browse");//浏览
	
	
	QHBoxLayout *cmdLyout =new QHBoxLayout；//水平布局对象
	cmdLyout->addWidget(openLabel);
	cmdLyout->addWidget(cmdLineEdit);
	
	QHBoxLayout *buttonLyout =new QHBoxLayout；
	cmdLyout->addWidget(commitButton);
	cmdLyout->addWidget(cancelButton);
	cmdLyout->addWidget(browseButton);
	
	
	QVBoxLayout *mainLyout =new QVBoxLayout；//垂直布局
	mainLyout->addWidget(infoLabel);
	mainLyout->addLayout(cmdLyout);//布局（对象）里加对象
	mainLyout->addWidget(buttonLyout);
	
	return app.exec();//返回程序死循环  exec ，程序永远在执行什 
	 
}
