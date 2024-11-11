
mod = 1000000007

# from math import factorial, ceil, pow, sqrt, floor, gcd
from sys import stdin, stdout
from collections import defaultdict, Counter, deque
# from bisect import bisect_left, bisect_right
# import sympy
# from itertools import permutations
# import numpy as np

#           n = int(stdin.readline())
#           stdout.write(str())
#           s = stdin.readline().strip('\n')
#           map(int, stdin.readline().split())
#           l = list(map(int, stdin.readline().split()))

for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    s1 = list(stdin.readline().strip('\n'))
    s2 = list(stdin.readline().strip('\n'))
    count = 0
    for i in range(n):
        if s2[i] == '1' and s1[i] == '0':
            count += 1
        elif s2[i] == '1':
            if i > 0 and s1[i-1] == '1':
                count += 1
                s1[i-1] = '-1'
            elif i < n-1 and s1[i+1] == '1':
                count += 1
                s1[i+1] = '-1'
    print(count)


