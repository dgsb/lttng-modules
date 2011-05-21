/*
 * probes/lttng-probe-block.c
 *
 * Copyright 2010 (c) - Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * LTTng block probes.
 */

#include <linux/module.h>
#include <linux/blktrace_api.h>

/*
 * Create the tracepoint static inlines from the kernel to validate that our
 * trace event macros match the kernel we run on.
 */
#include <trace/events/block.h>

/*
 * Create LTTng tracepoint probes.
 */
#define LTTNG_PACKAGE_BUILD
#define CREATE_TRACE_POINTS
#define TRACE_INCLUDE_PATH ../instrumentation/events/lttng-module

#include "../instrumentation/events/lttng-module/block.h"

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Mathieu Desnoyers <mathieu.desnoyers@efficios.com>");
MODULE_DESCRIPTION("LTTng block probes");