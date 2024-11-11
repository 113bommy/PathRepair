import sys
import math
import collections
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    n,a,b,c=get_ints()
    count=0
    if a==1 or b==1 or c==1:
        print(n)
        continue
    arr = [a, b, c]
    arr.sort(reverse=True)
    a, b, c = arr
    for i in range(math.floor(n/a)+1):
        left=n-(a*i)
        for j in range(math.ceil(left/b)):
            n_left=left-(j*b)
            if n_left%c==0:
                count=max(count,i+j+(n_left//c))
        if left==0:
            count=max(count,i)
    print(count)