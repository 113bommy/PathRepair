def main(inp):
    n, k, d = split_inp_int(inp)
    sols = []
    k = min(1000, k)
    import itertools
    source = itertools.product(*[range(1, k + 1) for __ in range(d)])
    for s in source:
        sols.append(s)
        if len(sols) == n:
            break
    if len(sols) < n:
        print(-1)
        return
    for i in range(d):
        for j in range(n):
            print(sols[j][i], end=" ")
        print()



def split_inp_int(inp):
    return list(map(int, inp().split()))


def use_fast_io():
    import sys

    class InputStorage:
        def __init__(self, lines):
            lines.reverse()
            self.lines = lines

        def input_func(self):
            if self.lines:
                return self.lines.pop()
            else:
                return ""

    input_storage_obj = InputStorage(sys.stdin.readlines())
    return input_storage_obj.input_func


from collections import Counter, defaultdict
from functools import reduce
import operator
import math


def product(arr_):
    return reduce(operator.mul, arr_, 1)

if __name__ == "__main__":

    main(use_fast_io())
