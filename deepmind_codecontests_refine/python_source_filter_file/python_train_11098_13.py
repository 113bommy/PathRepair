from sys import maxsize, stdout, stdin,stderr
mod = int(1e9 + 7)
import re #can use multiple splits
def tup():return map(int,stdin.readline().split())
def I(): return int(stdin.readline())
def lint(): return [int(x) for x in stdin.readline().split()]
def S(): return input().strip()
def grid(r, c): return [lint() for i in range(r)]
def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=stderr)
from  math import  log2,sqrt
from collections import defaultdict
s= S().split()
n = I()

d='^>v<'
if n%2==0:print('undefined')
else:
    st =d.find(s[0]).__index__()
    en = d[(st+n)%4]
    if en==s[1]:print('cw')
    elif d[abs(st-n)%4]==s[1]:print('ccw')
    else:print('undefined')

























