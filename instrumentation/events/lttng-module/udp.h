#undef TRACE_SYSTEM
#define TRACE_SYSTEM udp

#if !defined(LTTNG_TRACE_UDP_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_UDP_H

#include "../../../probes/lttng-tracepoint-event.h"
#include <linux/udp.h>

LTTNG_TRACEPOINT_EVENT(udp_fail_queue_rcv_skb,

	TP_PROTO(int rc, struct sock *sk),

	TP_ARGS(rc, sk),

	TP_STRUCT__entry(
		__field(int, rc)
		__field(__u16, lport)
	),

	TP_fast_assign(
		tp_assign(rc, rc)
		tp_assign(lport, inet_sk(sk)->inet_num)
	),

	TP_printk("rc=%d port=%hu", __entry->rc, __entry->lport)
)

#endif /* LTTNG_TRACE_UDP_H */

/* This part must be outside protection */
#include "../../../probes/define_trace.h"
