//
//  E2Server.hpp
//  e2
//
//  Created by NITIN KUMAR on 6/6/16.
//  Copyright © 2016 Juniper Networks. All rights reserved.
//

#ifndef E2Server_hpp
#define E2Server_hpp

#include <stdio.h>
#include <mutex>
#include <grpc++/grpc++.h>
#include "E2ServerProtos.h"
#include "Logger.hpp"


class E2Server final : public E2::E2::Service {
    const Logger *_logger;
    
public:
    E2Server(const Logger *logger) : _logger(logger)
    {
    }
    
};

#endif /* E2Server_hpp */