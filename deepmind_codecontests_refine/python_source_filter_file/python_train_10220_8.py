q=int(input())
for _ in range(q):
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    a=max(A)
    b=min(A)
    if(a-b-2>k):
        print(-1)
    else:
        print(b+k)