t=int(input())
for _ in range(t):
    n,x,a,b=map(int,input().split())
    if a > b:
        a,b=b,a
    if b-a+x >= n:
        print(n-1)
    else:
        print(b-a+x)