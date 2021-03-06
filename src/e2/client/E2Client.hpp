//
//  E2Client.hpp
//  e2
//
//  Created by NITIN KUMAR on 6/7/16.
//  Copyright © 2016 Juniper Networks. All rights reserved.
//

#ifndef E2Client_hpp
#define E2Client_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <grpc++/grpc++.h>
#include "e2_api.grpc.pb.h"
#include "Logger.hpp"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::Status;

using E2::E2;
using E2::ConfigurationReply;
using E2::NetworkElement;
using E2::NetworkElementList;
using E2::NetworkElementOpStateList;
using E2::NetworkElementOpState;
using E2::NetworkElementProperty;
using E2::NetworkElementType;

using E2::FabricAdjacency;
using E2::FabricAdjacencyList;

using E2::ServiceBinding;
using E2::ServicePhysicalEndpoint;
using E2::ServicePhysicalEndpointList;
using E2::ServiceEndpoint;
using E2::ServiceEndpointList;


// AGENT_SERVER_ADDRESS
extern std::string server_ip, server_port;
#define AGENT_SERVER_IP_PORT  (std::string((server_ip + ":" + server_port)))

// E2Client Class
class E2Client {
    std::string _name;
    std::string _logfile;
    bool _debug_log;
    
public:
    // Stub Variable
    std::unique_ptr<E2::E2::Stub> stub_;
    
    E2Client (std::shared_ptr<Channel> channel,
              const std::string& name,
              const std::string& logfile_dir) :
    stub_(E2::E2::NewStub(channel)), _name(name)
    {
        std::string s(logfile_dir);
        _logfile = s + _name;
        _debug_log = false;
    }
    
    ~E2Client();
    
    static E2Client *create(std::shared_ptr<Channel> channel,
                            std::string& name,
                            uint32_t id,
                            const std::string& logfile_dir);
    
    void addElement(std::string name, std::string mgmt_ip, uint8_t persona);
    void deleteElement(std::string name);
    void listElements();
    void addFabricAdjacency(std::string name, std::string ep1, std::string ep2);
    void removeFabricAdjacency(std::string name);
    void addService(std::string name, uint32_t vlan_identifier);
    void deleteService(std::string name);
    void addPhysicalAccess(std::string name, std::string element_name, std::string access_port);
    void removePhysicalAccess(std::string name);
    void placeService(std::string name,
                      std::string pe_1, std::string pe_2,
                      std::string physical_access);
    void deplaceService(std::string name,
                        std::string pe_1, std::string pe_2,
                        std::string physical_access);
};


#endif /* E2Client_hpp */
