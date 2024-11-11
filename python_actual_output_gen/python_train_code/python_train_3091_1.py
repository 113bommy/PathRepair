import sys
input=sys.stdin.readline

T=int(input())
for _ in range(T):
    n,m=map(int,input().split())
    A=[]
    for i in range(n):
        A.append(list(map(int,input().split())))

    no=0
    mv=10**9
    s=0
    for i in range(n):
        for j in range(m):
            if(A[i][j]<=0):
                no=no+1
            mv=min(mv,A[i][j])
            s=s+abs(A[i][j])

    if (no%2!=0):
        s=s+mv+mv

    print(s)
            
            
