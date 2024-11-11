#!/usr/bin/env python3

from math import *
from itertools import *
from collections import *
from bisect import *


if __name__ == '__main__':
    v = int(input())
    A = [(i+1,int(x)) for i,x in enumerate(input().split())]

    A.sort(key=lambda x : (x[1],-x[0]))

    length = v // A[0][1]

    if length == 0:
        print(-1)
    else:
        v -= length
        ans = [A[0][0]]*length

        m = A[0][1]
        A = list(map(lambda x : (x[0],x[1]-m), A))

        A.sort(reverse=True)

        for i in range(length):
            ok = False
            for digit,val in A:
                if val <= v:
                    ans[i] = digit
                    v -= val
                    ok = True
                    break
            if not ok:
                break

        print(''.join([str(i) for i in ans]))

