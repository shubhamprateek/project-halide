typedef void (*ctor)();
extern "C" ctor begin_constructors;
extern "C" ctor end_constructors;
extern "C" void call_ctors()
{
	for (ctor *i = &begin_constructors; i != &end_constructors; i++)
	{
		(*i)();
	}
}

#include "../include/frame_buffer.h"

extern "C" void k_main(const void *multiboot_structure, unsigned int multiboot_magic)
{
	FrameBuffer::Writer p(FrameBuffer::Colours::WHITE, FrameBuffer::Colours::GREEN);
	p.print("HalideOS, an experimental OS by DSC KIIT");
	while (1);
}