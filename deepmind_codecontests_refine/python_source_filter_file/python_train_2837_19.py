import sys,random
input=sys.stdin.readline
T=int(input())
for _ in range(T):
    n,m=map(int,input().split())
    A=[]
    for i in range(n):
        A.append(list(map(int,input().split())))

    rc,cc=0,0
    for i in range(n):
        for j in range(m):
            if (A[i][j]==1):
                rc=rc+1
                break

    for j in range(m):
        for i in range(n):
            if (A[i][j]==1):
                cc=cc+1
                break

    v=min(rc,cc)
    if (v%2==0):
        print("Vivek")
    else:
        print("Ashish")
        
