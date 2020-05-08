# distributed_application_using_RPC_protocol
The purpose of this project is to write a distributed application using a Remote Proce- dure Call (RPC) protocol. The client program running on a Linux workstation provides the interface to users. The server running on another station provides two computational services.

The client program gets the server’s name through the command line argument (i.e.
argv[1]). Then, based on the next command line option (-r or -u), the client invokes
the computation function sumsqrt range() or update list() on the server, gets the
result back, and prints it out.
Two examples are shown below. The first example computes the sum of the square root
from 2 to 6 (inclusive). The computation is executed on the machine degas. In the second
example, the client calls the remote function update list() which converts each value
F in the linked list by using the formula F ∗ F/10.0 and returns the updated linked list
back to the client.
spirit> rcalc degas -r 2 6
9.831822
spirit> rcalc degas -u 5 10 13 14 25
2.5 10.0 16.9 19.6 62.5
The server provides two services (i.e. functions). The function sumsqrt range() gets a
range N 1 ..N 2 from the client parameter and then calculates the sum of square roots.
Similarly, the function update list() gets a linked list of real numbers from the client and computes the values. Note that the server program should be run on another Linux workstation before the client starts.
When the server is running, open a terminal session on the client. Issue the command
rpcinfo -p servername to find the port number used by your RPC server. Take a
screenshot and explain the response from rpcinfo in your report.
