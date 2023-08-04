#include <iostream>
#include <string>
#include "foo.pb.h"

int main ()
{
    std::string data;
    {
    // Create a message and serialize it.
    Foo foo;
    foo.set_text("Hello World!");
    foo.add_numbers(5);
    foo.add_numbers(14);
    foo.add_numbers(42);

    foo.SerializeToString(&data);
    }
    {
    // Parse the serialized message and check that it contains the correct data.
    Foo foo;
    foo.ParseFromString(data);
    assert(foo.text() == "Hello World!");
    assert(foo.numbers_size() == 3);
    assert(foo.numbers(2) == 42);
    }

    return 0;
}