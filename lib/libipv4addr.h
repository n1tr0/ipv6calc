/*
 * Project    : ipv6calc
 * File       : libipv4addr.h
 * Version    : $Id: libipv4addr.h,v 1.2 2002/03/24 16:58:21 peter Exp $
 * Copyright  : 2002 by Peter Bieringer <pb (at) bieringer.de> except the parts taken from kernel source
 *
 * Information:
 *  Header file for libipv4addr.c
 */ 

#include <netinet/in.h>

/* typedefs */
#ifndef _libipv4addr_h

#define _libipv4addr_h 1

/* IPv4 address structure */
typedef struct {
	struct in_addr in_addr;		/* in_addr structure */
	uint8_t prefixlength;		/* prefix length (0-32) 8 bit */
	int flag_prefixuse;		/* =1 prefix length in use (CIDR notation) */
	unsigned int scope;		/* address scope value 16 bit*/
	int flag_valid;			/* address structure filled */
} ipv6calc_ipv4addr;


/* IPv4 address assignment structure */
typedef struct {
	const uint32_t ipv4addr;
	const uint32_t ipv4mask;
	const char *string_registry;
} s_ipv4addr_assignment;


#endif


/* prototypes */
extern uint8_t  ipv4addr_getoctett(const ipv6calc_ipv4addr *ipv4addrp, const unsigned int numoctett);
extern uint16_t ipv4addr_getword(const ipv6calc_ipv4addr *ipv4addrp, const unsigned int numword);
extern uint32_t ipv4addr_getdword(const ipv6calc_ipv4addr *ipv4addrp);

extern void ipv4addr_setoctett(ipv6calc_ipv4addr *ipv4addrp, const unsigned int numocett, const unsigned int value);
extern void ipv4addr_setword(ipv6calc_ipv4addr *ipv4addrp, const unsigned int numword, const unsigned int value);
extern void ipv4addr_setdword(ipv6calc_ipv4addr *ipv4addrp, const unsigned int value);

extern void ipv4addr_clear(ipv6calc_ipv4addr *ipv4addrp);
extern void ipv4addr_clearall(ipv6calc_ipv4addr *ipv4addrp);

extern unsigned int ipv4addr_gettype(const ipv6calc_ipv4addr *ipv4addrp);

extern int addr_to_ipv4addrstruct(const char *addrstring, char *resultstring, ipv6calc_ipv4addr *ipv4addrp);
extern int libipv4addr_ipv4addrstruct_to_string(const ipv6calc_ipv4addr *ipv4addrp, char *resultstring, const unsigned long formatoptions);

extern int libipv4addr_get_registry_string(const ipv6calc_ipv4addr *ipv4addrp, char *resultstring);