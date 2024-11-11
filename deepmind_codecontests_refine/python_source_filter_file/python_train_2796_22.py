from collections import deque

N,x = map(int,input().split())

if x <= 1 or x >= 2*N-1 :
    print("No")
else :
    print("Yes")
    
    q = deque([x])
    for i in range(1,N) :
        if x-i > 0 :
            q.appendleft(x-i)
        else :
            q.appendleft(2*N+x-i)
    for i in range(1,N) :
        if x+i < 2*N :
            q.append(x+i)
        else :
            q.append(x+i-(2*N-1))
    
    for p in q :
        print(p)
        