import sys
import math
import random
from collections import deque, defaultdict
#print = sys.stdout.write
from string import ascii_letters
letters = ascii_letters[:26].upper()
ONLINE_JUDGE = 0
from functools import lru_cache

 
if any(['--local' in i for i in sys.argv]) and not ONLINE_JUDGE:
    sys.stdin = open('input.txt', 'r', encoding='utf-8')
    #sys.stdin = open('27887.txt', 'r')
    sys.stdout = open('output.txt', 'w', encoding='utf-8')

for _ in range(int(input())):
    n, x, t = map(int, input().split())
    v = t // x
    res = 0
    res += v * (n - v)
    res += (0 + min(n, v) - 1) * min(n, v) // 2
    print(res)