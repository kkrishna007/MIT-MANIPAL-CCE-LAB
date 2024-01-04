/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1-------n2
//    point-to-point
//
 
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int
main (int argc, char *argv[])
{
  CommandLine cmd (__FILE__);
  cmd.Parse (argc, argv);
  
  //Take logs
  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  //Take n number of computers
  NodeContainer nodes;
  nodes.Create (3);
  //NodeContainer n01 = NodeContainer (nodes.Get (0), nodes.Get (1));
  //NodeContainer n12 = NodeContainer (nodes.Get (1), nodes.Get (2));

  // Choose your technology to communicate
  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));
  pointToPoint.SetQueue("ns3::DropTailQueue","MaxSize",StringValue ("50p"));

  //Install technology on computers
  NetDeviceContainer devices;
  NetDeviceContainer nd01 = pointToPoint.Install (nodes.Get (0), nodes.Get (1));
  NetDeviceContainer nd12 = pointToPoint.Install (nodes.Get (1), nodes.Get (2));
  //devices = pointToPoint.Install (nodes);
  
  //Asking to follow rules
  InternetStackHelper stack;
  stack.Install (nodes);

  //Assign IP address to communicate
  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");
  Ipv4InterfaceContainer i1 = address.Assign (nd01);
  
  Ipv4AddressHelper address1;
  address1.SetBase ("10.1.2.0", "255.255.255.0");
  Ipv4InterfaceContainer i2 = address.Assign (nd12);
  
  //Create a x type of server on port x
  UdpEchoServerHelper echoServer (9);

  //Install server on an node then Start and stop the server
  ApplicationContainer serverApps = echoServer.Install (nodes.Get (2));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));

  //Create x type of client and set its attribuites
  UdpEchoClientHelper echoClient (i2.GetAddress (1), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (5));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

  //Install the server then start and stop it
  ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (10.0));
  
  AsciiTraceHelper ascii;
  pointToPoint.EnableAsciiAll (ascii.CreateFileStream ("myfirst.tr"));

  //Run the simulation
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
