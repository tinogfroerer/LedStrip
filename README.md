# Led Strip Contest: Example Code
Here you can find example code for the Bastli Led Strip Contest 2015/2016 (http://bastli.ch/contest). You might use it for reference or as a starting point for your code.

If you have working code in some funny programming language like Haskell, please make a merge request.

## C ##
The C example can be compiled with:
* ```bash gcc -std=gnu99 -pedantic *.c -lm -o app```
	The `-lm` switch is required for the wavefunction, which uses `sin(x)`
* ```bash clang -pedantic -std=gnu99 *.c -lm -o app```
* ```bash mingw32-gcc *.c -lwsock32 -lm -pedantic -std=gnu99 -o app```
* Visual Studio has not been tested yet. May very well need some love.

### Documentation ###
Documentation is available through doxygen.
```bash
cd c/
doxygen doxyfile
```
(Or alternatively just read the headerfiles)
