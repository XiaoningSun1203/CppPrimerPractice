protoc --cpp_out=./saveCppFile ./foo.proto
g++ fooUse.cpp foo.pb.cc -lprotobuf