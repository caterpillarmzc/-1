
//��װUdpSocket�࣬ʵ�������������ṩ�򵥵�socket�ӿ�

#include<iostream>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define CHECK_RET(q) if((q)==false){return -1;}//��ⷵ��ֵq

class UdpSocket{
private:
	int _sockfd;
public:
	//�����׽���
	bool Socket() {
		//int socket(int domain, int type, int protocol);
		_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (_sockfd < 0) {
			std::cerr << "socket error\n";
			return false;
		}
		return true;
	}
	//�󶨵�ַ��Ϣ
	bool Bind(const std::string &ip, const uint16_t port) {
		//bind(int sockfd, struct sockaddr *addr,socklen_t addrlen)
		struct sockaddr_in addr;//IPV4�õ���sockaddr_in
		addr.sin_family = AF_INET;//��ַ������
		//uint16_t htons(uint16_t hostshort);
		addr.sin_port = htons(9000);//�������ֽ����16λ���ݣ�ת��λ�����ֽ������ݷ���
		//in_addr_t inet_addr(const char *cp);		
		addr.sin_addr.s_addr = inet_addr(ip.c_str());//inet_addr�����ʮ�����ַ���IP��ַת��Ϊ�����ֽ���IP��ַ
		int ret;
		socklen_t len = sizeof(struct sockaddr_in);
		ret = bind(_sockfd, (struct sockaddr*)&addr, len);
		if (ret < 0) {
			std::cerr << "bind error\n";
			return false;
		}
		return true;
	}

	//��������
	bool Send(const std::string &data, const std::string &peer_ip,
		const uint16_t peer_port) {
		//ssize_t sendto(int sockfd, const void *buf, size_t len, 
		//int flags,struct sockaddr *dest_addr, socklen_t addrlen);
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(peer_port);
		addr.sin_addr.s_addr = inet_addr(peer_ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = sendto(_sockfd, &data[0], data.size(), 0,
			(struct sockaddr*) &addr, len);
		if (ret < 0) {
			std::cerr << "sendto error\n";
			return false;
		}
		return true;
	}

	//��������
	bool Recv(std::string &buf, std::string &peer_ip,
		uint16_t &peer_port) {
		//ssize_t recvfrom(int sockfd, void *buf, size_t len, 
		//int flags,struct sockaddr *src_addr, socklen_t *addrlen)
		//�ɹ�������ʵ�ʽ��յ����ݳ���,ʧ�ܣ�-1
		struct sockaddr_in peer_addr;
		socklen_t len = sizeof(struct sockaddr_in);
		char tmp[4096] = { 0 };//������ջ�����
		int ret = recvfrom(_sockfd, tmp, 4096, 0,
			(struct sockaddr*)&peer_addr, &len);
		if (ret < 0) {
			std::cerr << "recvfrom error\n";
			return false;
		}
		//char *inet_ntoa(struct in_addr in);
		//�������ֽ���IP��ַת��Ϊ���ʮ�����ַ���IP��ַ
		peer_ip = inet_ntoa(peer_addr.sin_addr);
		//uint16_t ntohs(uint16_t netshort);
		//�������ֽ����16λ����ת��Ϊ�����ֽ�������
		peer_port = ntohs(peer_addr.sin_port);
		buf.assign(tmp, ret);//��tmp�п���ret���ȵ�����
		return true;
	}

	//�ر��׽���
	void Close() {
		close(_sockfd);
	}
};