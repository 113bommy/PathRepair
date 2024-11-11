t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    x=k/(n-1)
    if (x+k)%n==0:
        print(x+k-1)
    else:
        print(x+k)