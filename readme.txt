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
auto-generated classes. Events will work too.

- currently there is a problem upon deleting UserControl which I temporary 
solved by skipping Release call. One should investigate. It could be related to 
my inability to create UserControl winrt object with overrides interface. But 
it could also be something more general which I am missing here.

- as it is written everytime when requesting winrt objects through some 
interface (e.g FindName) or when using winrt_cast new allocation is needed. One
should probably recycle objects created before and possibly return pointer to 
the shared instance if requested more than once. AFAIK MFC took similar approach
because it also made difference between Win32 objects and MFC-mirrored objects.

- as it is written AddRefs and Release are called everytime winrt_ptr is copied.
R-value references are your friend here.

- at some places pointers to raw interfaces are transfered. It's because I 
didn't have time and mood to wrap everything in c++ clases. Auto-generator will
do.

- events are limited to 1 handler. This can be easilly extended. Also in current
implementation it's not really possible to disconnect event handler after the 
c++ instance was discarded. This can be fixed by moving the event token directly
to EventHandler winrt object or just reseting the callbacks in EventHandler.

- properties can be easily added if needed as outlined in Object.i.h. In current
implementation only Set/Get function pairs are implemented. Properties would be
implemented on top of them.

- asynchronous operations were not investigated. However I don't expect any
 problems here because PPL.next should come with some support for this.