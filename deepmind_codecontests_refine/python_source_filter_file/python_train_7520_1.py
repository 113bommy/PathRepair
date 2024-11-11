import sys
input = sys.stdin.readline
from collections import deque
 
t = int(input())

C = [] # cost
P = [-1 for i in range(t)] # parents
Y = [] # difference in types

X = [[] for i in range(t)]


for i in range(t):
    a,b,c = list(map(int, input().split()))
    C.append(a)
    Y.append(b-c)
    
for i in range(t-1):
    a,b = list(map(int, input().split()))
    a -= 1
    b -= 1
    X[a].append(b)
    X[b].append(a)
    
if sum(Y) != 0:
    print(-1)
    exit()
    
else:
    R = [] # list of nodes in order
    Q = deque([0])
    
    while Q:
        x = deque.popleft(Q)
        R.append(x)
        for c in X[x]:
            P[c] = x
            X[c].remove(x)
            deque.append(Q,c)
            
    #print(P)
    #print(R)
    
    for j in R[1:]:
        C[j] = min(C[j], C[P[j]])
        
    #print(Y)
    ans = 0
    
    for i in R[1:][::-1]:
        if Y[i] != Y[P[i]]:
            ans += C[P[i]] * min(abs(Y[i]), abs(Y[P[i]]))
        Y[P[i]] += Y[i]

    print(ans*2)