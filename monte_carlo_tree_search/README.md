## Monte Carlo Tree Search
### Background: Algorithm Framework
[Original Paper](paper/CG2006.pdf)

Algorithm Main Steps:

1. Selection
2. Expansion
3. Simulation / Rollout
4. Backpropagation

### Appendix: Build & Run
`CMakeList.txt` mainly for github workflows' building process.

If you want to build manually, use `Makefile` there. 

* Build

```shell
make
```

* Run:

```shell
./mcts.so
```

* Clean:

```shell
make clean
```