# Computer-Networks

# Computer Networks Projects

This repository contains various projects related to Computer Networks, implemented using Cisco Packet Tracer, TCP, and UDP protocols. Each folder includes solutions and source code for different networking tasks.

## Folders Overview

### 1. Cisco Projects

This folder contains projects created using Cisco Packet Tracer, covering topics such as VLANs, DHCP, DNS, routing, and NAT configuration.

#### Solved Problems:
1. Subnetting the given address class for all networks in the configuration. If IPs are insufficient, use false IPs.
2. VLAN configuration in one network with a second switch to demonstrate MODE TRUNK between switches.
3. Static IP assignment in a network (randomly), with DHCP on the server and on the router in all other cases.
4. Duplicate the project for static routing in one copy and dynamic routing in the other. Set appropriate default gateways.
5. DNS server configuration and DNS assignment on computers.
6. Web server configuration and DNS association for the web server.
7. Wireless router and NAT configuration.

### 2. TCP Projects

This folder contains C code for a TCP-based client-server application. The application handles sending data from the client to the server and processing the data on the server side.

#### Files:
- `c.c` (Client): Connects to the server, sends data, and processes the server's response.
- `s.c` (Server): Receives data from the client, processes it, and sends the result back to the client.

### 3. UDP Projects

This folder contains C code for a UDP-based client-server application. The project demonstrates real-time messaging using UDP sockets.

#### Files:
- `client.c`: A UDP client that sends and receives messages to/from the server.
- `server.c`: A UDP server that listens for client messages and responds accordingly.

## How to Run

### Cisco Projects
Open the Cisco project files in Cisco Packet Tracer to view and simulate the configurations.

### TCP Projects
1. Compile the server and client programs:
   ```bash
   gcc s.c -o server
   gcc c.c -o client

2. Run the server:
   ```bash
   ./server <port_number>

4. Run the client:
   ```bash
   ./client <port_number> <server_ip_address>

### UDP Projects
1. Compile the server and client programs:
   ```bash
   gcc server.c -o udp_server
   gcc client.c -o udp_client

2. Run the server:
   ```bash
   ./udp_server <port_number>


4. Run the client:
   ```bash
   ./udp_client <server_ip_address> <port_number>


### Requirements
For TCP/UDP projects: GCC compiler (or any other C compiler) and Linux/MacOS terminal or Windows with Cygwin.
For Cisco Projects: Cisco Packet Tracer.


