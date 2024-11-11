from sys import stdin, stdout, maxsize;  # mod = int(1e9 + 7);#import re  # can use multiple splits

# input = stdin.buffer.readline
tup = lambda: map(int, stdin.readline().split())
I = lambda: int(stdin.readline())
lint = lambda: [int(x) for x in stdin.readline().split()]
S = lambda: stdin.readline().replace('\n', '').strip()
# def grid(r, c): return [lint() for i in range(r)]
# def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=stderr)
stpr = lambda x: stdout.write(f'{x}' + '\n')
star = lambda x: print(' '.join(map(str, x)))
from math import ceil, floor
from _collections import defaultdict
from bisect import bisect_left, bisect_right

for _ in range(I()):
    n, k = tup()
    ls = lint()
    ans = [-1] * n
    cnt = 0
    for i in range(n):
        if ls[i] * 2 < k:
            ans[i] = 1
        elif ls[i] * 2 > k:
            ans[i] = 0
        else:
            cnt += 1
    for i in range(n):
        if ans[i]==-1:
            if cnt > 0:
                cnt-=2
                ans[i] = 1
            else:
                ans[i]=0
        cnt-=2
    print(*ans)




























