# Marlon's Util Library for Games

This is a library of utilities I've developed for my personal C++ game / graphics programming projects.
It builds with C++23, and it might build with earlier versions too.
Feel free to use it if you find it useful.

## Features

### Allocators

I've written a few memory allocators I've found useful, most notably `Stack_allocator` and `Free_list_allocator`.

### Containers

I've written near drop-in replacements for several C++ standard library containers, each with a non-allocating and allocating variant.
The non-allocating variants take a chunk of memory during construction and throw an exception if you try to exceed the pre-allocated capacity.

- `List` and `Allocating_list` are basically the same as `std::vector`.
- `Set`, `Map`, `Allocating_set`, and `Allocating_map` are slightly different than `std::unordered_set` and `std::unordered_map`.
  Specifically, `Allocating_set` and `Allocating_map` do not guarantee referential stability when they reallocate.
  Otherwise, their APIs are basically the same.
- `Pool` is an object pool using `Free_list_allocator` underneath.
  You hand it a chunk of memory during construction and you get constant-time allocations and deallocations of fixed-size objects.
