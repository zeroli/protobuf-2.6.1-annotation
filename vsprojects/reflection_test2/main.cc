#include <iostream>
#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/dynamic_message.h>

int main()
{
    google::protobuf::compiler::DiskSourceTree sourceTree;
    sourceTree.MapPath("project_root", "../../");
    google::protobuf::compiler::Importer importer(&sourceTree, nullptr);
    importer.Import("project_root/test.proto");
    auto descriptor1 = importer.pool()->FindMessageTypeByName("T.Test");
    google::protobuf::DynamicMessageFactory factory;
    auto proto1 = factory.GetPrototype(descriptor1);
    auto message1 = proto1->New();
    auto reflection1 = message1->GetReflection();
    auto field1 = descriptor1->FindFieldByName("id");
    reflection1->SetInt32(message1, field1, 1);
    std::cout << message1->DebugString() << std::endl;
    delete message1;
    return 0;
}