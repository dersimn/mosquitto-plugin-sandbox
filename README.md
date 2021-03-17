## Dependencies (Ubuntu 20.04)

For building mosquitto

    apt install build-essential git libc-ares-dev libwebsockets-dev libssl-dev xsltproc docbook-xsl uthash-dev libcjson-dev

For [Node.js](distributions/README.md at master · nodesource/distributions) 15.x

    curl -fsSL https://deb.nodesource.com/setup_15.x | sudo -E bash -
    sudo apt-get install -y nodejs

## Usage

    git clone --depth 1 -b pr/plugin-client-properties https://github.com/dersimn/mosquitto
    make

    cd mosquitto/plugins
    git clone https://github.com/dersimn/mosquitto-plugin-sandbox plugin-sandbox
    cd plugin-sandbox
    make

Edit `contrib/mosquitto.conf` for proper path to plugin, then run:

    ../../src/mosquitto -c contrib/mosquitto.conf -v

In a new Terminal run:

    cd mosquitto/plugins/plugin-sandbox/contrib
    npm i mqtt
    node client

### Expected output:

```
root@ubuntu-vm:/mnt/hgfs/mosquitto/plugins/plugin-sandbox# ../../src/mosquitto -c contrib/mosquitto.conf -v
1615989287: mosquitto version 2.0.8 starting
1615989287: Config loaded from contrib/mosquitto.conf.
1615989287: Loading plugin: /mnt/hgfs/mosquitto/plugins/plugin-sandbox/payload_printf.so
1615989287: Opening ipv4 listen socket on port 1883.
1615989287: Opening ipv6 listen socket on port 1883.
1615989287: Opening websockets listen socket on port 9001.
1615989287: mosquitto version 2.0.8 running
1615989289: New connection from 192.168.161.1:54765 on port 1883.
1615989289: New client connected from 192.168.161.1:54765 as someClient (p5, c1, k60, u'someUser').
1615989289: No will message specified.
1615989289: Sending CONNACK to someClient (0, 0)
1615989289: Received SUBSCRIBE from someClient
1615989289:     # (QoS 0)
1615989289: someClient 0 #
1615989289: Sending SUBACK to someClient
1615989289: Received PUBLISH from someClient (d0, q0, r0, m0, 'some/topic', ... (11 bytes))
client address: 192.168.161.1
client id: someClient
client username: someUser
payload: 'someMessage'
1615989289: Sending PUBLISH to someClient (d0, q0, r0, m0, 'some/topic', ... (11 bytes))
1615989289: Received DISCONNECT from someClient
1615989289: Client someClient disconnected.
```