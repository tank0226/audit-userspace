/* auparse.h --
 * Copyright 2006-08,2012-23 Red Hat Inc.
 * All Rights Reserved.
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
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor
 * Boston, MA 02110-1335, USA.
 *
 * Authors:
 *      Steve Grubb <sgrubb@redhat.com>
 */

#ifndef AUPARSE_HEADER
#define AUPARSE_HEADER

#include "auparse-defs.h"

#ifndef __attr_access
#  define __attr_access(x)
#endif
#ifndef __attr_dealloc
# define __attr_dealloc(dealloc, argno)
#endif
#ifndef __attr_dealloc_free
# define __attr_dealloc_free
#endif
#ifndef __attribute_malloc__
#  define __attribute_malloc__
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* Library type definitions */

/* opaque data type used for maintaining library state */
typedef struct opaque auparse_state_t;

typedef void (*user_destroy)(void *user_data);
typedef void (*auparse_callback_ptr)(auparse_state_t *au,
			auparse_cb_event_t cb_event_type, void *user_data);

/* General functions that affect operation of the library */
void auparse_destroy(auparse_state_t *au);
void auparse_destroy_ext(auparse_state_t *au, auparse_destroy_what_t what);
auparse_state_t *auparse_init(ausource_t source, const void *b)
	__attribute_malloc__ __attr_dealloc (auparse_destroy, 1);
int auparse_new_buffer(auparse_state_t *au, const char *data, size_t data_len)
	__attr_access ((__read_only__, 2, 3));
int auparse_feed(auparse_state_t *au, const char *data, size_t data_len)
	__attr_access ((__read_only__, 2, 3));
void auparse_feed_age_events(auparse_state_t *au);
int auparse_flush_feed(auparse_state_t *au);
int auparse_feed_has_data(const auparse_state_t *au);
int auparse_feed_has_ready_event(auparse_state_t *au);
void auparse_add_callback(auparse_state_t *au, auparse_callback_ptr callback,
			void *user_data, user_destroy user_destroy_func);
void auparse_set_escape_mode(auparse_state_t *au, auparse_esc_t mode);
int auparse_reset(auparse_state_t *au);
char *auparse_metrics(const auparse_state_t *au)
	__attribute_malloc__ __attr_dealloc_free;

/* Functions that are part of the search interface */
int ausearch_add_expression(auparse_state_t *au, const char *expression,
			    char **error, ausearch_rule_t how);
int ausearch_add_item(auparse_state_t *au, const char *field, const char *op,
			const char *value, ausearch_rule_t how);
int ausearch_add_interpreted_item(auparse_state_t *au, const char *field,
			const char *op, const char *value, ausearch_rule_t how);
int ausearch_add_timestamp_item(auparse_state_t *au, const char *op, time_t sec,
				unsigned milli, ausearch_rule_t how);
int ausearch_add_timestamp_item_ex(auparse_state_t *au, const char *op,
	time_t sec, unsigned milli, unsigned serial, ausearch_rule_t how);
int ausearch_add_regex(auparse_state_t *au, const char *regexp);
int ausearch_set_stop(auparse_state_t *au, austop_t where);
void ausearch_clear(auparse_state_t *au);

/* Function dealing with setting user space configuration items */
int auparse_set_eoe_timeout (time_t new_tmo);

/* Functions that are part of the auparse_normalize interface */

// This causes the current event to become normalized.
int auparse_normalize(auparse_state_t *au, normalize_option_t opt);

// Event kind accessor
const char *auparse_normalize_get_event_kind(const auparse_state_t *au);

// session accessor
int auparse_normalize_session(auparse_state_t *au);

// Subject accessing functions
int auparse_normalize_subject_primary(auparse_state_t *au);
int auparse_normalize_subject_secondary(auparse_state_t *au);
const char *auparse_normalize_subject_kind(const auparse_state_t *au);
int auparse_normalize_subject_first_attribute(auparse_state_t *au);
int auparse_normalize_subject_next_attribute(auparse_state_t *au);

// Action string accessor
const char *auparse_normalize_get_action(const auparse_state_t *au);

// Object accessing functions
int auparse_normalize_object_primary(auparse_state_t *au);
int auparse_normalize_object_secondary(auparse_state_t *au);
int auparse_normalize_object_primary2(auparse_state_t *au);
int auparse_normalize_object_first_attribute(auparse_state_t *au);
int auparse_normalize_object_next_attribute(auparse_state_t *au);
const char *auparse_normalize_object_kind(const auparse_state_t *au);

// Results accessor
int auparse_normalize_get_results(auparse_state_t *au);

// How accessor
const char *auparse_normalize_how(const auparse_state_t *au);

// Syscall key accessor
int auparse_normalize_key(auparse_state_t *au);

/* Functions that traverse events */
int ausearch_next_event(auparse_state_t *au);
int ausearch_cur_event(auparse_state_t* au);
int auparse_next_event(auparse_state_t *au);

/* Accessors to event data */
const au_event_t *auparse_get_timestamp(const auparse_state_t *au);
time_t auparse_get_time(const auparse_state_t *au);
unsigned int auparse_get_milli(const auparse_state_t *au);
unsigned long auparse_get_serial(const auparse_state_t *au);
const char *auparse_get_node(const auparse_state_t *au) __attr_dealloc_free;
int auparse_node_compare(const au_event_t *e1, const au_event_t *e2);
int auparse_timestamp_compare(const au_event_t *e1, const au_event_t *e2);
unsigned int auparse_get_num_records(const auparse_state_t *au);

/* Functions that traverse records in the same event */
int auparse_first_record(auparse_state_t *au);
int auparse_next_record(auparse_state_t *au);
unsigned int auparse_get_record_num(const auparse_state_t *au);
int auparse_goto_record_num(auparse_state_t *au, unsigned int num);

/* Accessors to record data */
int auparse_get_type(const auparse_state_t *au);
const char *auparse_get_type_name(const auparse_state_t *au);
unsigned int auparse_get_line_number(const auparse_state_t *au);
const char *auparse_get_filename(const auparse_state_t *au);
int auparse_first_field(const auparse_state_t *au);
int auparse_next_field(const auparse_state_t *au);
unsigned int auparse_get_num_fields(const auparse_state_t *au);
const char *auparse_get_record_text(const auparse_state_t *au);
const char *auparse_get_record_interpretations(const auparse_state_t *au);
const char *auparse_find_field(auparse_state_t *au, const char *name);
const char *auparse_find_field_next(auparse_state_t *au);
unsigned int auparse_get_field_num(const auparse_state_t *au);
int auparse_goto_field_num(const auparse_state_t *au, unsigned int num);

/* Accessors to field data */
const char *auparse_get_field_name(const auparse_state_t *au);
const char *auparse_get_field_str(const auparse_state_t *au);
int auparse_get_field_type(const auparse_state_t *au);
int auparse_get_field_int(const auparse_state_t *au);
const char *auparse_interpret_field(auparse_state_t *au);
const char *auparse_interpret_realpath(const auparse_state_t *au);
const char *auparse_interpret_sock_family(auparse_state_t *au);
const char *auparse_interpret_sock_port(auparse_state_t *au);
const char *auparse_interpret_sock_address(auparse_state_t *au);
#ifdef __cplusplus
}
#endif

#endif

