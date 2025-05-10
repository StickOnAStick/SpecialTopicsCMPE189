# CMPE 189 Special Topics

# HW4


## 1. 
`Consider the DSR protocol. In one version of the protocol, each node only forwards the first
RREQ it receives corresponding to any particular route discovery and drops the remaining copies
of the RREQ it may receive. Similarly, the destination node responds to the first RREQ by
sending a RREP and drops the remaining RREQ. Does this approach ensure that the source node
will discover the route containing the fewest number of links? Explain briefly. You may assume
that all the links have the same metric.`

**No**. This doesn't ensure that the source will always discover the optimal path. DSR finds a local minima but cannot test every path to find a global minima. This is actually a feature as it trades 100% accuracy for overall performance by reducing the time to find a path of transmission.

## 2a.
Consider a pair of nodes A and B close to each other such that a single hop route exists
between these nodes. Suppose that a TCP connection exists between A and B, with A sending
TCP data packets to B. Consider two possible approaches (in both cases, a protocol similar to
IEEE 802.11 is used at the MAC layer):

i. A SIngle channel is used: Both TCP data and TCP ack packets are sent on this channel. 

ii. Availbale bandwidth is divide into two channels, channels D and A. TCP data packets are sent on Channel D whereas TCP on chan A

Describe a potential performance benefit of approach (ii) over approach (i)


**Option two eliminates interfrence between data and ack packets, reducing the delay in each. Pipelining the TCP parallelized the throughput and reduces latency for each individual TCP response**


## 2b. What are the advantages and disadvantages of having TCP use the cwnd and ssthresh values from t 1 when starting to send data at t 2 ? What alternative would you recommend? Why?

### Pros
- Faster ramp up, reducing delays and overall increasing throughput
- Caches client information, again reducing processing time and allowing for throughput

### Cons
- Network can change, mitigating the caching / ramp up mentioned above.
- Bursty data can cause packet loss and congestion
- Unfair since t2 will start slow
- Long idle might drop request since ACK wasn't recieved.


# 3. Wireshark lab

### 1. What is the IP address and tcp port number used by the client.
Client (me): 172.16.13.201:54929
### 2. What is the gaia server's addr and tcp port?
128.119.245.12:80

### 3
Client (me): 172.16.13.201:54929

Why did they ask this again? 

### 4 What is the sequence number of the TCP SYN segment that is used to initiate the TCP connection between the client computer and gaia.cs.umass.edu? What is it in the segment that identifies the segment as a SYN segment?
SYN number is 0 in our case, the SYN flag is set to 1 indicating that it's a SYN segment.

### 5 What is the sequence number of the SYNACK segment sent by gaia.cs.umass.edu to the client computer in reply to the SYN? What is the value of the Acknowledgement field in the SYNACK segment? How did gaia.cs.umass.edu determine that value? What is it in the segment that identifies the segment as a SYNACK segment?

Gaia's SYN ACK number is 1 since we add 1 to the inital sequence, the SYN and ACK flags are both set to 1 to indicate SYNACK


### 10 Are there any retransmitted segments in the trace file? What did you check for (in the trace) in order to answer this question?

There was not. I verified by checking the sequence numbers of the various traces recieved from the endpoint. If we had retransmitted segments I would've seen the number incriment, decriment, then begin incrimenting again. 

### 11 How much data does the receiver typically acknowledge in an ACK? Can you identify cases where the receiver is ACKing every other received segment (see Table 3.2 on page 250 in the text).

Initally the ACK was small at ~560b, but then grew and stabalized at ~1460b. I actually did not observe any skipping in the ACK sequence unfortunately. I double verified the sequence numbers and data lengths twice but observed no instance where the ACK occured after 2*1460b.