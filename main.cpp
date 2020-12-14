#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include <google/protobuf/empty.pb.h>
#include "functorK/api/apf/service.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using google::protobuf::Empty;
using functorK::api::apf::ApfStructure;
using functorK::api::apf::ApfApi;

int main(int argc, char **argv) {
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    auto stub = functorK::api::apf::ApfApi::NewStub(channel);

    ClientContext context;

    Empty request;
    ApfStructure response;

    Status status = stub->FetchApfStructure(&context, request, &response);
    std::cout << "Reply received: " << response.organization() << std::endl;

    return 0;
}
