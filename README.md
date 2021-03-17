
## Usage

    git clone https://github.com/eclipse/mosquitto
    cd mosquitto/plugins

    git clone https://github.com/dersimn/mosquitto-plugin-sandbox plugin-sandbox
    cd plugin-sandbox

    make

Edit `contrib/mosquitto.conf` for proper path to plugin, then run:

    mosquitto -c contrib/mosquitto.conf -v

In a new Terminal run:

    cd mosquitto/plugins/plugin-sandbox/contrib
    npm i mqtt
    node client

### Expected output:

```
root@ubuntu-vm:/mnt/hgfs/mosquitto/plugins/plugin-sandbox# mosquitto -c contrib/mosquitto.conf -v
1615980364: mosquitto version 2.0.8 starting
1615980364: Config loaded from contrib/mosquitto.conf.
1615980364: Loading plugin: /mnt/hgfs/mosquitto/plugins/plugin-sandbox/payload_printf.so
1615980364: Opening ipv4 listen socket on port 1883.
1615980364: Opening ipv6 listen socket on port 1883.
1615980364: Opening websockets listen socket on port 9001.
1615980364: mosquitto version 2.0.8 running
1615980478: New connection from 192.168.161.1:54818 on port 1883.
1615980478: New client connected from 192.168.161.1:54818 as someClient (p5, c1, k60, u'someUser').
1615980478: No will message specified.
1615980478: Sending CONNACK to someClient (0, 0)
1615980478: Received SUBSCRIBE from someClient
1615980478:     # (QoS 0)
1615980478: someClient 0 #
1615980478: Sending SUBACK to someClient
1615980478: Received PUBLISH from someClient (d0, q0, r0, m0, 'some/topic', ... (11 bytes))
by-struct id: 192.168.161.1
by-struct username: someClient
by-struct password: someUser
by-base address: 192.168.161.1
by-base id: someClient
by-base username: someUser
by-base password: somePassword
payload: 'someMessage'
1615980478: Sending PUBLISH to someClient (d0, q0, r0, m0, 'some/topic', ... (11 bytes))
1615980478: Received DISCONNECT from someClient
1615980478: Client someClient disconnected.
```