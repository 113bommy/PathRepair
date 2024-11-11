t=int(input())
for _ in range(t):
    n,m=map(int,input().split(' '))
    arr = list(map(int, input().split()))
    s=0
    for i in range(1,n):
        s=s+arr[i]
    print(min(s,m))