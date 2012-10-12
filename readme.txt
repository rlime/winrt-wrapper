This is v2 of true c++ winrt wrapper. It works with most recent windows8

Some technical observations
---------------------------

- main objective met: Access to WinRT objects through ISO C++ library. No crazy 
CX extensions. No Platform::Strings. Just some WRL hidden under friendly c++ 
interfaces. There is a projected C++ class for each WinRT component which 
comunicates with its winrt counterpart. You can see yourself how it is 
implemented and if it could be auto-generated from metadata. Observe some .winmd
files with ILDASM and see what kind of information it gives you. My bet is yes 
it can completely be auto-generated (I didn't go so far to write auto-generator 
myself. Everything in Generated folder is written manually. The Object.i.h file 
is technicaly not auto-generated, only copied) 

- i didn't focus on creating c++ class and exporting it as a new winrt object 
(with its interfaces, metadata etc.). It turned out that you don't need to do
this to build winrt app. If you don't want to create component reusable from 
other languages everything you need is to inherit your classes from 
auto-generated classes. Events will work too. If you want to do this you need
reverse generator which will generate WRL wrappers from your c++ classes.

- Currently c++ wrapper classes are allocated but never freed. Cache for
already allocated objects should be implemented so you minimize ammount
of allocations. Keep user objects in memory is also important for managing
events. Some objects can be created on stack like in RoutedEventHandler

- at some places pointers to raw interfaces are transfered. It's because I 
didn't have time and mood to wrap everything in c++ clases. Auto-generator will
do.

- properties can be easily added if needed as outlined in Object.i.h. In current
implementation only Set/Get function pairs are implemented. Properties would be
implemented on top of them.

- asynchronous operations were not fully investigated. The problem here is
PPL comes with support for IASyncOperation but it gets compiled only when 
C++/CX is used. Can be implemented by passing std::function completion handlers.