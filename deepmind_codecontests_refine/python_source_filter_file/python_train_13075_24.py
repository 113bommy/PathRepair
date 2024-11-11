from sys import maxsize, stdout, stdin,stderr
mod = int(1e9 + 7)
import re #can use multiple splits
tup = lambda : map(int,stdin.readline().split())
I = lambda :int(stdin.readline())
lint=lambda : [int(x) for x in stdin.readline().split()]
S = lambda :stdin.readline().replace('\n','').strip()
def grid(r, c): return [lint() for i in range(r)]
def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=stderr)
from  math import  log2,sqrt
from collections import defaultdict
n, m = tup()
s = S() ; t = S() ; cnt =0
mi = maxsize
arr =[];ans =[]
for i in range(m):
    x = t[i:i+n]
    if len(x)==n:
        arr =[]
        for j in range(n):
            if x[j] != s[j]:
                cnt+=1
                arr.append(i+j+1)
        #print(cnt)
        if cnt < mi:
            mi = cnt
            ans.append(arr)
        cnt =0
print(mi)
print(*ans[len(ans)-1])













