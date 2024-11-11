import sys
input = sys.stdin.buffer.readline
 
t = int(input())
 
for _ in range(t):
    a,b = list(map(int, input().split()))
    
    N = [[] for j in range(a)]
   
    for j in range(b):
        x,y = list(map(int, input().split()))
        N[x-1].append(y-1)
        
    visited = {}
    rem = set([])
    
    D = [0] * a
    
    for i in range(a):
        if D[i]<2:
            for j in N[i]:
                D[j] = max(D[j], D[i] + 1)
                
        else:
            rem.add(i)
    
    
    rem = list(rem)
    print(len(rem))
    print(*rem)