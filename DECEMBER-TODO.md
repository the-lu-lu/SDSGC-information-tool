# TODO

I'd like to once again go over all the code and make organisational changes.

## Organisation/documentation
- [ ] Add code documentation e.g. change comments to Doxygen style

## Project.h and main.cpp
- [ ] Consider the places exceptions are currently thrown, e.g. file and input validation - how much of my error handling HAS TO be exceptions? I should make custom exception types for those that do. I should make appropriate update to calling functions including: main, and all documentation.
- [ ] Should the main menu be handled in main.cpp or Menu.cpp...?

## Hero.h, Heroes.h and Hero.cpp, Heroes.cpp
- [ ] When should I be using arrays vs vectors? THINK about it.
- [ ] Think about using more STL algorithms (like std::copy_n instead of writing array literal)
- [ ] Think about whether the utility functions in Heroes.h belong in Utilities.h?
- [ ] ReadOwnedData and ReadHeroesData are extremely similar, think about it...
- [ ] Think about constants and globals

## Menu.h and Menu.cpp
- [ ] CPP Core Guidelines says "Do not use array subscript when the index is not an integer constant expression"... Maybe think about it.

## Utilities.h, Utilities.cpp
- [ ] Which of these functions (a) need to exist and (b) need to be in this separate file?
- [x] Please can I move the templates from the header file to the cpp file?

## Filter.h and Filter.cpp
- [x] Think about organisation decision that could fix the need to call HashKeys(ReadLists()) in Filter::GetArguments()

## AddOwned.h and AddOwned.cpp

## Bugs
- [x] Would be great to be able to run it, why are there all these linker errors???
