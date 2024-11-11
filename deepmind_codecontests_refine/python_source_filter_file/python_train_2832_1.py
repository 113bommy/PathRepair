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
    n = ii()
    a = list(ip())
    b = list(ip())

    x = [0]*(26)
    y = [0]*(26)

    for i in a :
        x[ord(i)-97] += 1

    for i in b :
        y[ord(i)-97] += 1
    
    if (x!=y) :
        print("NO")
        continue

    ma = max (x)

    if (ma > 1) :
        print("YES")
        continue

    t1 = 0

    for i in range (len(a)) :
        for j in range (i,len(a)-1) :
            if (a[j]<a[j+1]) :
                a[j],a[j+1] = a[j+1],a[j]
                t1 += 1

    t2 = 0

    for i in range (len(b)) :
        for j in range (i,len(b)-1) :
            if (b[j]<b[j+1]) :
                b[j],b[j+1] = b[j+1],b[j]
                t2 += 1

    if (t1-t2)%2 == 0 :
        print("YES")
    else :
        print("NO")

    
            
        
            
        

        
