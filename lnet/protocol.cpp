#include <iostream>
#include <functional>
#include <netdb.h>

using std::cout;
using std::endl;

void display_protocol(struct protoent* pt) {
	int i = 0;
	if(pt) {
		cout << "protocol name:" << pt->p_name << endl;
		if(pt->p_aliases) {
			cout << "alias name:";
			while(pt->p_aliases[i]) {
				cout << pt->p_aliases[i] << endl;
				i++;
			}
		}
		cout << "value:" << pt->p_proto << endl;
	} else {
		cout << "pt failed" << endl;
	}
}

int main() {
	int i = 0;
	const char* proto_name[] = {
		"ip",
		"icmp",
		NULL
	};

	setprotoent(1);
	while(proto_name[i] != NULL) {
		struct protoent *pt = getprotobyname((const char*)proto_name[i]);
		if(pt) {
			display_protocol(pt);
		}
		i++;
	}
	endprotoent();
	return 0;
	

}
 
