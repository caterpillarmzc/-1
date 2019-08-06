#include "udpsocket.hpp"
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "./udp_cli ip port\n";//�жϸ�ʽ�Ƿ���ȷ
		return -1;
	}
	uint16_t port;
	std::string ip = argv[1];
	std::stringstream tmp;
	tmp << argv[2];//�ҵ���
	tmp >> port;

	UdpSocket sock;//ʵ����
	CHECK_RET(sock.Socket());//����������false,ֱ�ӷ���-1
	//�ͻ��˲��Ƽ��û������󶨹̶���ַ����Ϊһ���˿�ֻ�ܱ�һ������ռ��
	//���һ���˿ڹ̶�������ͻ��˳����ֻ������һ��
	while (1) {
		std::string buf;
		std::cin >> buf;
		//��socket��û�а󶨵�ַ����ʱ�����ϵͳ�ڷ���֮ǰ���Լ�⵽
		//��ʱ�����ϵͳ��Ϊsocketѡ��һ�����ʵĵ�ַ�Ͷ˿ڽ��а�
		sock.Send(buf, ip, port);

		buf.clear();
		sock.Recv(buf, ip, port);
		std::cout << "server say:" << buf << std::endl;
	}
	sock.Close();
	return 0;
}
