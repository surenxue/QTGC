#include <QApplication>
#include <QLabel>//��ǩͷ�ļ� 

#include <QLineEdit>
#include <QPushButton>//��ťͷ�ļ� 
#include <QHBoxLayout>//ˮƽ����
#include <QVBoxLayout>//��ֱ����

#include <QWig>
int main(int argc,char *argc[]) {
	QApplication app(argc,argv);
	
	QLabel *infoLabel  = new QLabel;
	QLabel *openLabel  = new QLabel;
	
	QLineEdit *cmdLineEdit = new QLinEdit;
	
	QPushButton *commitButton= new QPushButton;
	QPushButton *cancelButton= new QPushButton;
	OPushButton *browseButton = new OPushButton:
	
	
	infoLabel-> setText("input cmd");//��ǩ1
	openLabel-> setText("open");//��ǩ2
	
	commitButton-> setText("commit");//ȷ��
	cancelButton-> setText("cancel");//ȡ��
	browseButton-> setText("browse");//���
	
	
	QHBoxLayout *cmdLyout =new QHBoxLayout��//ˮƽ���ֶ���
	cmdLyout->addWidget(openLabel);
	cmdLyout->addWidget(cmdLineEdit);
	
	QHBoxLayout *buttonLyout =new QHBoxLayout��
	cmdLyout->addWidget(commitButton);
	cmdLyout->addWidget(cancelButton);
	cmdLyout->addWidget(browseButton);
	
	
	QVBoxLayout *mainLyout =new QVBoxLayout��//��ֱ����
	mainLyout->addWidget(infoLabel);
	mainLyout->addLayout(cmdLyout);//���֣�������Ӷ���
	mainLyout->addWidget(buttonLyout);
	
	return app.exec();//���س�����ѭ��  exec ��������Զ��ִ��ʲ 
	 
}
