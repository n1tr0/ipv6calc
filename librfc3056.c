/*
 * Project    : ipv6calc
 * File       : librfc3056.c
 * Version    : $Id: librfc3056.c,v 1.1 2002/02/27 23:07:15 peter Exp $
 * Copyright  : 2001-2002 by Peter Bieringer <pb (at) bieringer.de>
 *
 * Information:
 *  Function library for conversions defined in RFC 1884
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ipv6calc.h"
#include "librfc3056.h"


/*
 * function converts an IPv4 address to an IPv6to4 one (RFC 3056)
 *  
 * in : *ipv4addrp = IPv4 address
 * out: *resultstring = result
 * ret: ==0: ok, !=0: error
 */
#define DEBUG_function_name "librfc3056/ipv4addr_to_ipv6to4addr"
int ipv4addr_to_ipv6to4addr(ipv6calc_ipv6addr *ipv6addrp, ipv6calc_ipv4addr *ipv4addrp) {
	int retval = 1, i;

	/* set prefix */
	ipv6addr_setword(ipv6addrp, 0, 0x2002);

	/* set IPv4 address */
	for (i = 0; i <=3; i++) {
		ipv6addr_setoctett(ipv6addrp, i + 2, ipv4addr_getoctett(ipv4addrp, i));
	};

	retval = 0;
	return (retval);
};
#undef DEBUG_function_name

