/* vim:ts=8:sts=8:sw=4:noai:noexpandtab
 *
 * portable doubly-linked list.
 *
 * Copyright (c) 2010 Miru Limited.
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

#ifndef __PGM_LIST_H__
#define __PGM_LIST_H__

#include <glib.h>


struct PGMList
{
	gpointer 		data;
	struct PGMList*		next;
	struct PGMList*		prev;
};

typedef struct PGMList PGMList;


G_BEGIN_DECLS

PGMList* pgm_list_append (PGMList*, gpointer) G_GNUC_WARN_UNUSED_RESULT;
PGMList* pgm_list_prepend_link (PGMList*, PGMList*) G_GNUC_WARN_UNUSED_RESULT;
PGMList* pgm_list_remove_link (PGMList*, PGMList*) G_GNUC_WARN_UNUSED_RESULT;
PGMList* pgm_list_delete_link (PGMList*, PGMList*) G_GNUC_WARN_UNUSED_RESULT;
PGMList* pgm_list_last (PGMList*);
guint pgm_list_length (PGMList*);


G_END_DECLS

#endif /* __PGM_LIST_H__ */