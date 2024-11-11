import sys
from collections import deque
from queue import PriorityQueue
import math
input_ = lambda: sys.stdin.readline().strip("\r\n")
ii = lambda : int(input_())
il = lambda : list(map(int, input_().split()))
ilf = lambda : list(map(float, input_().split()))
ip = lambda : input_()
fi = lambda : float(input_())
ap = lambda ab,bc,cd : ab[bc].append(cd)
li = lambda : list(input_())
pr = lambda x : print(x)
prinT = lambda x : print(x)
f = lambda : sys.stdout.flush()
 
 
for _ in range (ii()) :
    n,k = il()
    a = list(ip())
 
    ind = 0
 
    b = []
 
    for i in range (n) :
        if (a[i] == '0') :
            mn = max(ind,i-k)
            b.append(mn)
            xy = i-mn
            
            k = max(k-xy,0)
            #print(k,mn,xy)
            ind += 1
    #print(b)
 
    if (len(b) == 0) :
        print(a)
    else :
        ans = ['1']*n
 
        for i in b :
            #print(i)
            ans[i] = '0'
 
        print(''.join(ans))
        
