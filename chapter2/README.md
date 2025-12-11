# Chapter 2
* Use -O0 to perserve symbol names
* gdb and lldb
* use `valgrind ./main` to detect memory errors

## Valgrind
Attach debugger at first error
```bash
valgrind --db-attach=yes ./main
```
To do memory leak check:
```bash
valgrind --leak-check=full ./main
```

## doxygen
```bash
doxygen -g # generates Doxyfile
doxygen
```
## tests
```bash
sh main_test.sh
sh test_coverage.sh
```

## cweb
`.w` files, can be converted into `.tex` (`cweave example.w`) and then `.pdf`.