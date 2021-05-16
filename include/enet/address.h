/**
 @file  address.h
 @brief ENet address constants and macros
*/
#ifndef __ENET_ADDRESS_H__
#define __ENET_ADDRESS_H__

#if ENET_HAS_IPV6_SUPPORT
#define ENET_AF_INET AF_INET6
#define ENET_PF_INET PF_INET6
#define ENET_SOCKADDR sockaddr_in6
#define ENET_SET_FAMILY(sin) (sin.sin6_family = ENET_AF_INET)
#else
#define ENET_AF_INET AF_INET
#define ENET_PF_INET PF_INET
#define ENET_SOCKADDR sockaddr_in
#define ENET_SET_FAMILY(sin) (sin.sin_family = ENET_AF_INET)
#endif

extern void enet_address_host_from_sockaddr (ENetAddress * address, const struct ENET_SOCKADDR * input);
extern void enet_address_host_to_sockaddr (struct ENET_SOCKADDR * input, const ENetAddress * address);
extern void enet_address_from_sockaddr (ENetAddress * address, const struct ENET_SOCKADDR * input);
extern void enet_address_to_sockaddr (struct ENET_SOCKADDR * input, const ENetAddress * address);

#endif /* __ENET_ADDRESS_H__ */

