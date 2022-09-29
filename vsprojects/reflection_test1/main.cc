#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "test.pb.h"
#include <cassert>
#include <iostream>

int main()
{
    auto descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("T.Test");
    assert(descriptor);
    auto prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
    assert(prototype);

    auto message = prototype->New();
    auto test = dynamic_cast<T::Test*>(message);
    test->set_id(1);
    std::cout << test->DebugString() << std::endl;
    delete message;
    return 0;
}