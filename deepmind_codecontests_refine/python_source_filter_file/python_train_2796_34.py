from collections import deque

N,x = list(map(int,input().split()))

if x==2*N-1 or x==1:
    print("No")
else:
    Q=deque()
    if x<=N:
        Q.append(x)
        Q.append(x-1)
        for i in range(2*N-1,0,-1):
            if i!=x and i!=x-1:
                if i%2==0:
                    Q.append(i)
                else:
                    Q.appendleft(i)
    else:
        Q.append(x)
        Q.append(x+1)
        for i in range(1,2*N):
            if i!=x and i!=x-1:
                if i%2==0:
                    Q.append(i)
                else:
                    Q.appendleft(i)

    print("Yes")

    while len(Q)>0:
        print(Q.pop())