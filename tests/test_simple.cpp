#include "enet/enet.h"

#include <cstdio>
#include <string>

int main()
{
	ENetAddress hostAddr { ENET_HOST_ANY, 0 };
	ENetHost* host = enet_host_create(&hostAddr, 1, 1, 0, 0);

	ENetAddress addr;
	addr.port = 80;
#if ENET_HAS_IPV6_SUPPORT
	addr.host.data[10] = 0x13;
	addr.host.data[11] = 0x37;
#else
	addr.host = 1337;
#endif
	// Initiate connection to server
	ENetPeer* peer = enet_host_connect(host, &addr, 1, 0);
	if (!peer)
		printf("ERROR: no peer on %i", __LINE__);

#if ENET_HAS_IPV6_SUPPORT
	char buf[200];
	enet_address_get_host_ip(&addr, buf, 200);
	printf("%s\n", std::string(buf).c_str());
	enet_address_set_host(&addr, "lobby.wildfiregames.com");
	enet_address_get_host_ip(&addr, buf, 200);
	printf("%s\n", std::string(buf).c_str());
	enet_address_set_host(&addr, "google.com");
	enet_address_get_host_ip(&addr, buf, 200);
	printf("%s\n", std::string(buf).c_str());
#else
	char buf[200];
	printf("%i ", enet_address_get_host_ip(&addr, buf, 200));
	printf("%s\n", std::string(buf).c_str());
	printf("%i ", addr.host);
	printf("%i ", enet_address_set_host(&addr, "lobby.wildfiregames.com"));
	printf("%i\n", addr.host);
	printf("%i ", enet_address_get_host_ip(&addr, buf, 200));
	printf("%s\n", std::string(buf).c_str());
	printf("%i ", enet_address_set_host_ip(&addr, "136.243.44.163"));
	printf("%i\n", addr.host);
	printf("%i ", enet_address_get_host_ip(&addr, buf, 200));
	printf("%s\n", std::string(buf).c_str());
	printf("%i ", enet_address_set_host(&addr, "google.com"));
	printf("%i ", enet_address_get_host_ip(&addr, buf, 200));
	printf("%s\n", std::string(buf).c_str());
#endif

	enet_host_destroy(host);

	printf("\nDone\n\n");
	return 0;
}
