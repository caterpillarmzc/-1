#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{
	while (1) {
		printf("[san@localhost]$ ");
		fflush(stdout);

		char tmp[1024] = { 0 };
		scanf("%[^\n]%*c", tmp);
		printf("[%s]\n", tmp);

		//��Ҫ�������ַ�������������������+����
		//"   ls -a -l" -> "ls"  "-a" "-l"
		char *ptr = tmp;
		int argc = 0;
		char *argv[32] = { NULL };
		while (*ptr != '\0') {
			if (!isspace(*ptr)) {
				//ָ���ߵ��ǿհ��ַ���
				argv[argc] = ptr;
				argc++;
				while (!isspace(*ptr) && *ptr != '\0') ptr++;
				*ptr = '\0';
				ptr++;
				continue;
			}
			ptr++;
		}
		argv[argc] = NULL;
		//argv[0]=ls  argv[1] = -l argv[2] = -a

		//�жϵ�ǰ�����Ƿ����ڽ�����
		if (!strcmp(argv[0], "cd")) {
			//�ı䵱ǰ����·��
			chdir(argv[1]);
			continue;
		}

		int pid = fork();
		if (pid == 0) {
			execvp(argv[0], argv);
			//���ӽ��̳����滻ʧ�ܣ���ֱ���˳�,��Ϊ�ն˲���Ҫ���shell
			exit(0);
		}
		//�ȴ��ӽ����˳������⽩ʬ����
		wait(NULL);
	}
	return 0;
}
