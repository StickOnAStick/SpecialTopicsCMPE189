# Homework 3
#### Nicholas D 014307618

# Task 1

- 802.11 physical layer transmission rate = 54Mbps
- MAC layer data payload = 1452 bytes
- MAC header = 28 bytes
- ACK Frame Size = 14 bytes
- RTS Frame Size = 20 bytes
- CTS Frame Size = 14 bytes
- SIFS Time = 16 μs (microseconds)
- DIFS Time = 34 μs (microseconds)
- Average time spent in backoff = 36 μs (microseconds)

**MAC layer throughput** is defined as the number of bits sent by the MAC layer in a given period
of **time (1s)**. Answer the following questions:

## [lp1] If there are two stations exchaning data using 802.11 dcf but without using RTS/CTS transaction, what is MAC layer throughput?

Transmission time (data) = 11840 bits / 54 Mbps = **219.26us**

ACK transmission = 112 bits / 54 Mbps = **2.07us**

$T_{total} = DIFS + BackOff + T_{data} + SIFS + T_{ACK}$

$T_{total} = 34 + 36 + 219.6 + 16 + 2.07$

$T_{total} = 307.33us$

**Throughput = 11,616 bits / 307.33 us = 37.79 Mbps**


## [LP2] What is the throughput when RTS/CTS is used?

$T_{total} = DIFS + BackOff + T_{RTS} + SIFS + T_{CTS} + T_{data} + SIFS + T_{ACK}$

$T_{Total} = 34 + 36 + 2.96 + 16 + 2.07 + 16 + 219.26 + 16 + 2.07$

$T_{total} = 344.36 us$

^ Latex doesn't allow two equalities on the same line :/

**Throughput = 11,616 bits / 344.36 us = 33.72 Mbps**


# Task 2 - Ns3 simulations on hidden terminal

## [LP] You will perform a simulation that illustrates the hidden terminal problem. The file examples/wireless/wifi-hidden-terminal.cc demonstrates the hidden terminal problem.

Copy the example into the scratch folder and run it. Explain the output of the program. Specifically,
how does the throughput change when RTS-CTS in introduced, and why?


- The code demonstrates an example where **Nodes 0 and 2 cannot hear eachother** but can still communicate with **node 1**
- Without RTS/CTS they will collide at node 1 and cause errors; however, with rts/cts they will **ask for permission to send in order to avoid collisions.**
- This added step decreases the throughput as we need to transfer more overall data and ensure that we can actually transmit (adding timers, retrys etc); **HOWEVER, it does NOT decrease it MORE than the example with NO RTS/CTS.** This is because we avoid collisions and experience **less overall packet loss with RTS/CTS.**  

## [HP] Modify the file you copied into the scratch folder and modify the default loss of the MatrixPropagationLossModel to 50. 

The MatrixPropagationLossModel is a theoretical model that
allows you to set path loss between pairs of nodes and is by default symmetric. Read more about
it [here](https://www.nsnam.org/docs/release/3.39/doxygen/d5/d4d/classns3_1_1_matrix_propagation_loss_model.html). Now run the experiment and report the result. Explain the results, specifically how it
compares to the solution in LP.

### Results with propagation loss at 50db instead of 200db:
```bash
Flow 1 (10.0.0.1 -> 10.0.0.2)
  Tx Packets: 2410
  Tx Bytes:   3441480
  TxOffered:  3.05909 Mbps
  Rx Packets: 1506
  Rx Bytes:   2150568
  Throughput: 1.91162 Mbps
Flow 2 (10.0.0.3 -> 10.0.0.2)
  Tx Packets: 2411
  Tx Bytes:   3442908
  TxOffered:  3.06036 Mbps
  Rx Packets: 1543
  Rx Bytes:   2203404
  Throughput: 1.95858 Mbps
------------------------------------------------
Hidden station experiment with RTS/CTS enabled:
Flow 1 (10.0.0.1 -> 10.0.0.2)
  Tx Packets: 2410
  Tx Bytes:   3441480
  TxOffered:  3.05909 Mbps
  Rx Packets: 1586
  Rx Bytes:   2264808
  Throughput: 2.01316 Mbps
Flow 2 (10.0.0.3 -> 10.0.0.2)
  Tx Packets: 2411
  Tx Bytes:   3442908
  TxOffered:  3.06036 Mbps
  Rx Packets: 1470
  Rx Bytes:   2099160
  Throughput: 1.86592 Mbps
```

### Results with prop loss at 200db (original result):
```bash
Flow 1 (10.0.0.1 -> 10.0.0.2)
  Tx Packets: 2410
  Tx Bytes:   3441480
  TxOffered:  3.05909 Mbps
  Rx Packets: 108
  Rx Bytes:   154224
  Throughput: 0.137088 Mbps
Flow 2 (10.0.0.3 -> 10.0.0.2)
  Tx Packets: 2411
  Tx Bytes:   3442908
  TxOffered:  3.06036 Mbps
  Rx Packets: 100
  Rx Bytes:   142800
  Throughput: 0.126933 Mbps
------------------------------------------------
Hidden station experiment with RTS/CTS enabled:
Flow 1 (10.0.0.1 -> 10.0.0.2)
  Tx Packets: 2410
  Tx Bytes:   3441480
  TxOffered:  3.05909 Mbps
  Rx Packets: 1331
  Rx Bytes:   1900668
  Throughput: 1.68948 Mbps
Flow 2 (10.0.0.3 -> 10.0.0.2)
  Tx Packets: 2411
  Tx Bytes:   3442908
  TxOffered:  3.06036 Mbps
  Rx Packets: 876
  Rx Bytes:   1250928
  Throughput: 1.11194 Mbps
```

### Results / Conclusion

## 200db
- Without RTS/CTS High collision rates <5% success
- RTS/CTS significantly improved throughput

## 50db
- Node 0 and 2 can hear eachother yapping, preventing simultaneous transmission & reducing collisions
- RTS/CTS not needed as both nodes can hear eachother and the extra overhead is somewhat detrimental to the performance of the system **(1.6Mbps w/o rts/cts vs. 1.11Mbps with)**


## Task 3 - WireShark analysis of 802.11 Wifi

**1. What are the SSIDS of the two access points**
- linksys_SES_24086
- 30 Munroe St.

**2. What are the intervals of the time between transmissions of the beacon frames.**
- Both are 1.02 seconds.

**3. What is the source MAC addr. on the beacon frame from 30 Munroe St.**
- 00:16:b6:f7:1d:51

**4. What is the destination MAC addr on the beacon frame from 30 Munro st.**
- MAC DEST: ff:ff:ff:...:ff

**5. What is the MAC BSS id on the beacon frame from 30 Munro St.**
- 00:16:b6:f7:1d:51

**6. What are the four primary and eight additional data rates the beacon frames from 30 munro st advertise they can support.**
- Four: 1, 2, 5.5, 11 Mbps
- Eight Additional: 6, 9, 12, 18, 24, 36, 48, 54 Mbps

**7. Find the 802.11 frame containing the Syn TCP, what are the MAC address fields in the 802.11 frame. Which MAC address in the frame correwsponds to the wireless host? To the access Point? To the first-hop router? What is the IP addr. of the host sending this TCP segment? What is the desitnation IP? Does this Destination IP correspond to the host, access point, first-hop, or some other network-attached device? Explain. Yikes.**
- Wireless Host: 00:13:02:d1:b6:4f
- First hop: 00:16:b6:f4:eb:a8
- Wireless host sending this tcp segment is: 00:16:b6:f7:1d:51
- IP of wireless host:: 192.168.1.109
- Destination of IP is 128.199.245.12 (host).

**8. Find the 802.11 frame containing the SYNACK segment for this TCP session. What are three MAC address fields in the 802.11 frame? Which MAC address in this frame corresponds to the host? To the access point? To the first-hop router? Does the sender MAC address in the frame correspond to the IP address of the device that sent the TCP segment encapsulated within this datagram? (Hint: review Figure 6.19 in the text if you are unsure of how to answer this question, or the corresponding part of the previous question. It’s particularly important that you understand this)**

- BSS id:  00:16:b6:f7:1d:51
- Dest (host): 00:13:02:d1:b6:4f
- Source (first-hop): 00:16:b6:f4:eb:a8
- The sender does not correspond to the IP of the server which sent the request since we had to go through the first-hop. 