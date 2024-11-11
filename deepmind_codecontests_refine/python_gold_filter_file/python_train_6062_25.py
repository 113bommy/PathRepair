t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    arr=list(map(int,input().split()))
    diff=m-arr[0]
    if sum(arr[1:])>=diff:
        print(m)
    else:
        d=sum(arr[1:])
        print(d+arr[0])