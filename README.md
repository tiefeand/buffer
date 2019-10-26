# tutorial_buffer
A simple implementation of a buffer object.  This has been my very first C++ library.

This library visualizes some of the atomic base concept of the language C++. Building
up this little library helped me to get familiar with:

Pointer arithmetic:
As the library content is not more than memory handlinc It makes use of pointer arithmetic.
This library reveals nicely how asteriks or ambersant are to be used and what their effective
concequence is when using it within one or the other local context

Dynamically allocated memory:
The library also helps understanding the usage of how memory is dynamically to be allocated
and how it is freed. In conjunction with the class oriented approach it also points out the
importance of handling it well structured and abstracted rather than entangled and nested.

Class oriented programing:
Conceptually clean separation between constructors and destructores. The constructor being
further divided into object instanciation and initialization. Constructor and destructor
can further be regarded as different from accessor methods. They only come into play when
memory is allocated memory. Yet accessor methods are valid members even when the object
is statically allocated.

Generic programming using templates:
The library shows haow to use templates in order to eliminate doublicated code.

Differences between C++ and C:
While being a C++ library it does not use some of the fundamental C++ keywords such as new 
and delete. It rather uses simple C functionality.  
