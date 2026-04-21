## Robot Path Planning
* [Monte Carlo Tree Search](monte_carlo_tree_search/)
* [Rapidly Exploring Random Tree (RRT)](rapidly_exploring_random_tree/)
* [AStar (A*)](astar/)

### Appendix: Build & Run
`CMakeList.txt` mainly for github workflows' building process.

If you want to build manually using `CMakeLists.txt`, use following commands:

```shell
# build
mkdir build && cd build
cmake ..
make
```

Run:

```shell
# mcts
./monte_carlo_tree_search/mcts.so
# rrt
./rapidly_exploring_random_tree/rrt.so
# AStar (A*)
./astar/astar.so
```

Clean:

```shell
make clean
cd ..
rm -rf build/
```
