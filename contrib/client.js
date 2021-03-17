/*
    Run with:

        npm i mqtt
        node client
*/

var mqtt = require('mqtt');
var client  = mqtt.connect('mqtt://192.168.161.6', {
    clientId: 'someClient',
    username: 'someUser',
    password: 'somePassword',
    protocolVersion: 5
});

client.on('error', function (error) {
    console.log(error)
});

client.on('connect', function () {
    client.subscribe('#');
    
    client.publish('some/topic', 'someMessage', {
        properties: {
            userProperties: {
                'foo': 'bar'
            }
        }
    });
});

client.on('message', function (topic, message, packet) {
    console.log(packet);
    client.end();
});
