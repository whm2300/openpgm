/* vim:ts=8:sts=8:sw=4:noai:noexpandtab
 * 
 * Internet header for protocol version 4, RFC 791.
 *
 * Copyright (c) 1982, 1986, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Copyright (c) 1996-1999 by Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#ifndef __PGM_IP_H__
#define __PGM_IP_H__

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include <glib.h>

#ifdef G_OS_UNIX
#	include <netdb.h>
#	include <sys/socket.h>
#else
#	include <ws2tcpip.h>
#endif


/* 1-byte alignment */
#pragma pack(push, 1)

/* RFC 791 */

/* nb: first four bytes are forced bitfields for win32 "feature" */
struct pgm_ip
{
#if G_BYTE_ORDER == G_LITTLE_ENDIAN
	unsigned int	ip_hl:4;		/* header length */
	unsigned int	ip_v:4;			/* version */
#elif G_BYTE_ORDER == G_BIG_ENDIAN
	unsigned int	ip_v:4;			/* version */
	unsigned int	ip_hl:4;		/* header length */
#else
#	error unknown ENDIAN type
#endif
	unsigned int	ip_tos:8;		/* type of service */
	unsigned int	ip_len:16;		/* total length */
	guint16		ip_id;			/* identification */
	guint16		ip_off;			/* fragment offset field */
	guint8		ip_ttl;			/* time to live */
	guint8		ip_p;			/* protocol */
	guint16		ip_sum;			/* checksum */
	struct in_addr	ip_src, ip_dst;		/* source and dest address */
};


#ifndef G_STATIC_ASSERT
#       define G_PASTE_ARGS(identifier1,identifier2) identifier1 ## identifier2
#       define G_PASTE(identifier1,identifier2) G_PASTE_ARGS (identifier1, identifier2)
#       define G_STATIC_ASSERT(expr) typedef struct { char Compile_Time_Assertion[(expr) ? 1 : -1]; } G_PASTE (_GStaticAssert_, __LINE__)
#endif

G_STATIC_ASSERT(sizeof(struct pgm_ip) == 20);

/* RFC 2460 */
#ifdef ip6_vfc
#	undef ip6_vfc
#endif
#ifdef ip6_plen
#	undef ip6_plen
#endif
#ifdef ip6_nxt
#	undef ip6_nxt
#endif
#ifdef ip6_hops
#	undef ip6_hops
#endif
struct pgm_ip6_hdr
{
	guint32		ip6_vfc;		/* version:4, traffic class:8, flow label:20 */
	guint16		ip6_plen;		/* payload length: packet length - 40 */
	guint8		ip6_nxt;		/* next header type */
	guint8		ip6_hops;		/* hop limit */
	struct in6_addr	ip6_src, ip6_dst;	/* source and dest address */
};

G_STATIC_ASSERT(sizeof(struct pgm_ip6_hdr) == 40);

/* RFC 768 */
struct pgm_udphdr
{
	guint16		uh_sport;		/* source port */
	guint16		uh_dport;		/* destination port */
	guint16		uh_ulen;		/* udp length */
	guint16		uh_sum;			/* udp checksum */
};

G_STATIC_ASSERT(sizeof(struct pgm_udphdr) == 8);

#pragma pack(pop)

#endif /* __PGM_IP_H__ */