from sys import maxsize, stdout, stdin, stderr
# mod = int(1e9 + 7)
import re  # can use multiple splits
tup = lambda: map(int, stdin.readline().split())
I = lambda: int(stdin.readline())
lint = lambda: [int(x) for x in stdin.readline().split()]
S = lambda: stdin.readline().replace('\n', '').strip()
def grid(r, c): return [lint() for i in range(r)]
def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=stderr)
stpr = lambda x  : stdout.write(f'{x}' + '\n')
star = lambda x : print(' '.join(map(str , x)))
from collections import *
from math import *
for _ in range(I()):
    a , b = tup()
    t = b
    if a%b!=0:
        print(a)
        continue
    d = defaultdict(int)
    while b%2==0:
        b//=2
        d[2]+=1
    for i in range(2, int(b**0.5) +  1 , 2):
        while b%i==0:
            b//=i
            d[b]+=1
        #if i==1:break
    if b > 2:
        d[b]+=1
    ans = 1
    #print(d)
    for i in d:
        p = a
        cnta,cntb = 0,0
        while p%i==0:
            p//=i
            cnta+=1
        #print(cnta , d[i] + 1 )
        ans = max(ans , a// i**(cnta - d[i] + 1))
    print(ans)



















