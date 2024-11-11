import sys
import math
import collections
from os import path
from collections import defaultdict

mod = (10 ** 9) + 7
sys.setrecursionlimit(10 ** 6)

if path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
test = int(sys.stdin.readline().rstrip())
while test > 0:
    test -= 1
    n = int(sys.stdin.readline().rstrip())
    ans = ""
    if n % 2 == 0:
        ans = 'a' * (n // 2)
        ans += 'b'
        ans += 'a' * ((n // 2) - 1)
    else:
        ans = 'a' * (n // 2)
        ans += 'b'
        ans += 'a' * ((n // 2) - 1)
        ans += 'c'
    print(ans)
