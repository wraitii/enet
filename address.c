/**
 @file  address.c
 @brief ENet address functions
*/

#define ENET_BUILDING_LIB 1
#include <string.h>
#include "enet/enet.h"

#if ENET_HAS_IPV6_SUPPORT
ENetAddressHost ENET_HOST_ANY = ENET_HOST_ANY_INIT;
#endif

void
enet_address_host_from_sockaddr (ENetAddress * address, const struct ENET_SOCKADDR * input)
{
#if ENET_HAS_IPV6_SUPPORT
    memcpy(& address -> host, & input->sin6_addr.s6_addr + sizeof (input->sin6_addr.s6_addr) - sizeof (address -> host), sizeof (address -> host));
#else
    memcpy(& address -> host, & input->sin_addr.s_addr + sizeof (input->sin_addr.s_addr) - sizeof (address -> host), sizeof (address -> host));
#endif
}

void
enet_address_host_to_sockaddr (struct ENET_SOCKADDR * input, const ENetAddress * address)
{
#if ENET_HAS_IPV6_SUPPORT
    memcpy(input->sin6_addr.s6_addr, & address -> host, sizeof (address -> host));
#else
    memcpy(& input->sin_addr.s_addr, & address -> host, sizeof (address -> host));
#endif
}


void
enet_address_from_sockaddr (ENetAddress * address, const struct ENET_SOCKADDR * input)
{
	enet_address_host_from_sockaddr(address, input);
#if ENET_HAS_IPV6_SUPPORT
    address -> port = ENET_NET_TO_HOST_16 (input->sin6_port);
#else
    address -> port = ENET_NET_TO_HOST_16 (input->sin_port);
#endif
}

void
enet_address_to_sockaddr (struct ENET_SOCKADDR * input, const ENetAddress * address)
{
	enet_address_host_to_sockaddr(input, address);
#if ENET_HAS_IPV6_SUPPORT
    input->sin6_port = ENET_HOST_TO_NET_16 (address -> port);
#else
    input->sin_port = ENET_HOST_TO_NET_16 (address -> port);
#endif
}

int
enet_address_compare_host (const ENetAddress * a, const ENetAddress * b)
{
    return memcmp(& a -> host, & b -> host, sizeof (a -> host));
}
