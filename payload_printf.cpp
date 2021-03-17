#include <stdio.h>
#include <string.h>

#include "mosquitto_broker.h"
#include "mosquitto_plugin.h"
#include "mosquitto.h"
#include "mqtt_protocol.h"
#include "mosquitto_internal.h"

#define UNUSED(A) (void)(A)

static mosquitto_plugin_id_t *mosq_pid = NULL;

static int callback_message(int event, void *event_data, void *userdata)
{
	struct mosquitto_evt_message *ed = (mosquitto_evt_message*)event_data;

	UNUSED(event);
	UNUSED(userdata);

	/*
		For some reason struct obtained with this 'Hack' is shifted.
		Maybe lib/mosquitto_internal.h -> stuct mosquitto is compiled with different preprocessor ifdefs?
	*/
	printf("by-struct id: %s\n", ed->client->id);               // prints IP address
	printf("by-struct username: %s\n", ed->client->username);	// prints client id
	printf("by-struct password: %s\n", ed->client->password);	// prints username
	
	// workaround: Find base by tria & error:
	char **base = &ed->client->id;

	printf("by-base address: %s\n", base[0]);
	printf("by-base id: %s\n", base[1]);
	printf("by-base username: %s\n", base[2]);
	printf("by-base password: %s\n", base[3]);

	printf("payload: '%.*s'\n", ed->payloadlen, (char *)ed->payload);

	return MOSQ_ERR_SUCCESS;
}

int mosquitto_plugin_version(int supported_version_count, const int *supported_versions)
{
	int i;

	for(i=0; i<supported_version_count; i++){
		if(supported_versions[i] == 5){
			return 5;
		}
	}
	return -1;
}

int mosquitto_plugin_init(mosquitto_plugin_id_t *identifier, void **user_data, struct mosquitto_opt *opts, int opt_count)
{
	UNUSED(user_data);
	UNUSED(opts);
	UNUSED(opt_count);

	mosq_pid = identifier;
	return mosquitto_callback_register(mosq_pid, MOSQ_EVT_MESSAGE, callback_message, NULL, NULL);
}

int mosquitto_plugin_cleanup(void *user_data, struct mosquitto_opt *opts, int opt_count)
{
	UNUSED(user_data);
	UNUSED(opts);
	UNUSED(opt_count);

	return mosquitto_callback_unregister(mosq_pid, MOSQ_EVT_MESSAGE, callback_message, NULL);
}
