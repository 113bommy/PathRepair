from sys import *
input = stdin.readline

for _ in range(1):
    
    n,p = map(int,input().split())
    a = list(map(int,input().split()))
    
    m = max(a)
    
    d = [0]*(4005)
    for i in a:
        d[i] += 1
        
    w = []
    
    
    for i in range(m-n+1,m+1): 
        
        v = 0 
        for j in range(i):
            v += d[j]
            
        ans = 1
        for j in range(i,i+n):
            v = v + d[j]
            ans = (ans%p * v%p)%p
            v -= 1
        if(ans%p != 0):
            w.append(i)
    
    print(len(w))
    print(*w)