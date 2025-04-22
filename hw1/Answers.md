# Homework 1

# Task 1 NS3
## 1. Ns3 install & instructions
See code, got it working with user parameters.


## 2. Complete the table for the given data rates / packet sizes: 

### Server reception time
| Pkt size\Data rate | 512bps | 1Kbps | 512Kbps | 1Mbps |
|--------------------|--------|-------|---------|-------|
|128   | 2.4705s  | 1.266s | 0.00446875s | 0.003264s |
| 256  | 4.47075s | 2.29s  | 0.00646875s | 0.004288s | 
| 1024 | 16.4707s | 8.434s | 0.0184687s  | 0.010432s |

### Client reception time
| Pkt size\Data rate | 512bps | 1Kbps | 512Kbps | 1Mbps |
|--------------------|--------|-------|---------|-------|
|128   | 4.9415s  | 2.532s | 0.0089375s | 0.006528s |
| 256  | 8.9415s | 4.58s  | 0.0129375s | 0.008576s | 
| 1024 | 32.9415s | 16.868s | 0.0369375s  | 0.020864s |


## 3 [HP1] Add another echo client application to the left-most p2p node (n0), and another echo server application to the right-most CSMA node (n4). Answer the following questions:

1. Comment on the port number attribute of the echo server and client. Should you pay
special attention to it while setting up your new server and client? Why?

- Yes you need to otherwise we'd run into port-binding errors and packets could be mis-matched (req 1 recieved req 2's data). 

2. Report the time at which a message is received at the server and the client with 1 and 2 applications running.
```bash
nick@DESKTOP-0D4T5U5:~/School/SpecialTopicsCMPE189/ns-3-allinone/ns-3.43$ ./ns3 run 'scratch/mySecond.cc'
Consolidate compiler generated dependencies of target scratch_mySecond
At time +2s client sent 1024 bytes to 10.1.2.4 port 9
At time +2.0118s server received 1024 bytes from 10.1.1.1 port 49153
At time +2.0118s server sent 1024 bytes to 10.1.1.1 port 49153
At time +2.02161s client received 1024 bytes from 10.1.2.4 port 9
At time +3s client sent 1024 bytes to 10.1.2.4 port 10
At time +3.00378s server received 1024 bytes from 10.1.1.1 port 49154
At time +3.00378s server sent 1024 bytes to 10.1.1.1 port 49154
At time +3.00756s client received 1024 bytes from 10.1.2.4 port 10
```

## 4 [HP2] Copy mythird.cc into mythird-hw1.cc. Make the following changes: Instead of the placing the echo server in the CSMA nodes, place it in one of the mobile WiFi stations

**1. You will now record the throughput of the application using a FlowMonitorHelper**
- Copied code from provided example to achieve this.

**2. Run the new code and report the throughput**
```bash
At time +2s client sent 1024 bytes to 10.1.3.1 port 9
At time +2.00262s server received 1024 bytes from 10.1.3.4 port 49153
At time +2.00262s server sent 1024 bytes to 10.1.3.4 port 49153
At time +2.00959s client received 1024 bytes from 10.1.3.1 port 9
Flow 1 (10.1.3.4 -> 10.1.3.1)
  Tx Packets: 1
  Tx Bytes:   1052
  Rx Bytes:   1052
  Throughput: 3.21416 Mbps
Flow 2 (10.1.3.1 -> 10.1.3.4)
  Tx Packets: 1
  Tx Bytes:   1052
  Rx Bytes:   1052
  Throughput: 1.20743 Mbps
```

**3. Change the number of wifi devices to 6+ last digit of Student ID**

Student ID: 014307618
nWifiDevices = 6 + 8 = **14**

```bash
At time +2s client sent 1024 bytes to 10.1.3.1 port 9
At time +2.00361s server received 1024 bytes from 10.1.3.14 port 49153
At time +2.00361s server sent 1024 bytes to 10.1.3.14 port 49153
At time +2.01063s client received 1024 bytes from 10.1.3.1 port 9
Flow 1 (10.1.3.14 -> 10.1.3.1)
  Tx Packets: 1
  Tx Bytes:   1052
  Rx Bytes:   1052
  Throughput: 2.33449 Mbps
Flow 2 (10.1.3.1 -> 10.1.3.14)
  Tx Packets: 1
  Tx Bytes:   1052
  Rx Bytes:   1052
  Throughput: 1.19827 Mbps
```

No geo-spatial data is provided by the flow monitor, all other requirements can be seen in the output.



# Task 2

## 5 [LP3] Complete the WireShark lab and answer Questions 1-3

1. Which of the following protocols are shown as appearing in your trace file?
    - TCP primarily with some UDP and TLSv1.2

2. How long did it take from when the HTTP GET message was sent until the HTTP OK reply was recieved? 
   - Sent: **25.675663** Recieved: **25.821715** Time Taken: **0.15**

3. What is the internet address of the gai.cs.umass.edu. What is the internet address of your computer?
   - My IP: **172.16.13.201**  Gaia IP: **128.119.245.12**

## 6 [HP3] Answer Questions 4-6

4. What browser issued the HTTP GET request? 
    - User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36

5. Expand the information on the TCP protocol for this packet, What is the desitnation port number which the request is being sent to?
   - Destination port 80 (standard http port)

6. Print the two HTTP messages GET and OK reffered to in question 2 above.
   - See the pdf attached inside this directories **/images** folder.



