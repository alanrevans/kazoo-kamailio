/**
 * $Id$
 *
 * dmq module - distributed message queue
 *
 * Copyright (C) 2011 Bucur Marius - Ovidiu
 *
 * This file is part of Kamailio, a free SIP server.
 *
 * Kamailio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * Kamailio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef _DMQ_H_
#define _DMQ_H_

#include "../../dprint.h"
#include "../../error.h"
#include "../../sr_module.h"
#include "../../modules/tm/tm_load.h"
#include "../../parser/parse_uri.h"
#include "../../modules/sl/sl.h"
#include "bind_dmq.h"
#include "peer.h"
#include "worker.h"

#define DEFAULT_NUM_WORKERS	2
#define MIN_PING_INTERVAL	60

extern int num_workers;
extern dmq_worker_t* workers;
extern dmq_peer_t* dmq_notification_peer;
extern str dmq_server_address;
extern dmq_peer_list_t* peer_list;
extern str dmq_request_method;
extern struct sip_uri dmq_server_uri;
extern str dmq_notification_address;
extern struct sip_uri dmq_notification_uri;
/* sl and tm */
extern struct tm_binds tmb;
extern sl_api_t slb;

extern str dmq_200_rpl;
extern str dmq_400_rpl;
extern str dmq_500_rpl;
extern str dmq_404_rpl;

static inline int dmq_load_api(dmq_api_t* api) {
	bind_dmq_f binddmq;
	binddmq = (bind_dmq_f)find_export("bind_dmq", 0, 0);
	if ( binddmq == 0) {
		LM_ERR("cannot find bind_dmq\n");
		return -1;
	}
	if (binddmq(api) < 0)
	{
		LM_ERR("cannot bind dmq api\n");
		return -1;
	}
	return 0;
}

int dmq_handle_message(struct sip_msg* msg, char* str1 ,char* str2);

#endif

