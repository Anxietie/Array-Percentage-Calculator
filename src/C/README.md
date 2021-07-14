The C version of this program runs a little differently from the python and java versions.

Below are a list of changed functionality:
- Input is split up (1 value at a time)
- Floating points are accepted

For all the versions however, I wrote them all using basic libraries/imports.
Using special libraries/imports to do the half the work seemed boring, so these are the very basics of the programs.
Because C doesn't have any map/dictionary implementations (as far as I know without libraries), it was significantly more complicated.
To get around this, I used a 2d array (not an actual array, a mallocated int pointer) and mapped the rows' indecies to eachother (to essentially recreate a map/dictionary).
