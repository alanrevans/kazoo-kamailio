/*
 * $Id$
 *
 * db_berkeley module, portions of this code were templated using
 * the dbtext and postgres modules.

 * Copyright (C) 2007 Cisco Systems
 *
 * This file is part of SIP-router, a free SIP server.
 *
 * SIP-router is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * SIP-router is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * History:
 * --------
 * 2007-09-19  genesis (wiquan)
 */

/*! \file
 * Berkeley DB : Module API
 *
 * \ingroup database
 */


#ifndef _BDB_MOD_H
#define _BDB_MOD_H

extern int auto_reload;
extern int log_enable;
extern int journal_roll_interval;

#endif /* _BDB_MOD_H */
