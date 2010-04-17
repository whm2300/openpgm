/* vim:ts=8:sts=4:sw=4:noai:noexpandtab
 * 
 * PGM packet formats, RFC 3208.
 *
 * Copyright (c) 2006 Miru Limited.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __PGM_PACKET_PARSE_H__
#define __PGM_PACKET_PARSE_H__

#include <sys/socket.h>
#include <pgm/framework.h>
#include <pgm/skbuff.h>

PGM_BEGIN_DECLS

bool pgm_parse_raw (struct pgm_sk_buff_t* const, struct sockaddr* const, pgm_error_t**);
bool pgm_parse_udp_encap (struct pgm_sk_buff_t* const, pgm_error_t**);
bool pgm_verify_spm (const struct pgm_sk_buff_t* const);
bool pgm_verify_spmr (const struct pgm_sk_buff_t* const);
bool pgm_verify_nak (const struct pgm_sk_buff_t* const);
bool pgm_verify_nnak (const struct pgm_sk_buff_t* const);
bool pgm_verify_ncf (const struct pgm_sk_buff_t* const);
bool pgm_verify_poll (const struct pgm_sk_buff_t* const);
bool pgm_verify_polr (const struct pgm_sk_buff_t* const);

PGM_END_DECLS

#endif /* __PGM_PACKET_PARSE_H__ */
