#!/usr/bin/env python3

from itertools import combinations, permutations
from operator  import *

NUM = 1

def main():
    funcs = [and_, or_, ne]
    funcs += [lambda a, b, f=f: not f(a, b) for f in funcs]

    num = -1
    for fd, fu, fy in combinations(funcs, 3):
        for fd, fu, fy in permutations((fd, fu, fy)):
            num += 1
            if num == NUM:
                x0, x1, x2, x3 = (int(input()) for i in range(4))
                a = fu(x0, x1)
                b = fy(x2, x3)
                c = fd(x1, x2)
                d = fu(x0, x3)
                e = fd(a, b)
                f = fy(c, d)
                g = fu(e, f)
                print(int(g))
                break

main()
