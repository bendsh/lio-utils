/*
 * Copyright (c) 2006 SBE, Inc.
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "common.h"

#define LIO_ISCSI_VERSION "3.0"

extern void init_iscsiMib(void);
extern void init_scsiMib(void);
extern void init_ipsAuthMib(void);

void
target_mib_version(unsigned int clientreg, void *clientarg)
{
    snmp_log(LOG_INFO, "Linux-iSCSI.org Target Mib Module version %s\n",
             LIO_ISCSI_VERSION);
}

/* Initializes the iscsiTargetMib module */
void
init_iscsiTargetMib(void)
{
    init_iscsiMib();
    init_scsiMib();
    init_ipsAuthMib();
    /* Setup callback for mib module version logging */
    snmp_alarm_register(1, 0, target_mib_version, NULL);
}
