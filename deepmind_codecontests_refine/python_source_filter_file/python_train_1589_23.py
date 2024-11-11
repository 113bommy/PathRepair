t=int(input())
for i in range(t):
    x,y,n=map(int,input().split())
    z=n//x
    a=(z*x)+y
    if a<n:
        print(a)
    else:
        print(a-x)