/* Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Antonin Bas (antonin@barefootnetworks.com)
 *
 */

#pragma once

#include "stddef.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

// Initializes necessary resources. Should only be called once.
void PIGrpcServerInit();

// Same as PIGrpcServerInit but supports providing a serialized
// p4::server::v1::Config Protobuf message (in text format) for P4Runtime server
// configuration.
void PIGrpcServerInitWithConfig(const char *config_text, const char *version);

// Set ForwardingPipelineConfig for dev_id statically.
// It is necessary when someone wants to install ForwardingPipelineConfig via programming API instead of P4Runtime.
int PIGrpcServerPipelineConfigSet(uint64_t dev_id, const char *config_bin, size_t data_size, void *p4info);

// Start server and bind to default address (0.0.0.0:50051)
void PIGrpcServerRun();

// Start server and bind to given address (eg. localhost:1234,
// 192.168.1.1:31416, [::1]:27182, etc.)
void PIGrpcServerRunAddr(const char *server_address);

// Start server and bind to given address (eg. localhost:1234,
// 192.168.1.1:31416, [::1]:27182, etc.) and an optional third-party gNMI
// service. Note that the implementation will expect the void* must be a
// pointer of type gnmi::gNMI::Service, and free it as a part of
// PIGrpcServerCleanup
void PIGrpcServerRunAddrGnmi(const char *server_address, void *gnmi_service);

// Get port number bound to the server
int PIGrpcServerGetPort();

// Get number of PacketIn packets sent to client
uint64_t PIGrpcServerGetPacketInCount(uint64_t device_id);

// Get number of PacketOut packets sent to DevMgr
uint64_t PIGrpcServerGetPacketOutCount(uint64_t device_id);

// Wait for the server to shutdown. Note that some other thread must be
// responsible for shutting down the server for this call to ever return.
void PIGrpcServerWait();

// Shutdown server but waits for all RPCs to finish
void PIGrpcServerShutdown();

// Force-shutdown server with a deadline for all RPCs to finish
void PIGrpcServerForceShutdown(int deadline_seconds);

// Once server has been shutdown, cleanup allocated resources.
void PIGrpcServerCleanup();

#ifdef __cplusplus
}
#endif
