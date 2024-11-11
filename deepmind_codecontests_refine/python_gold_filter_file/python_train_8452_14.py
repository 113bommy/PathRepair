t = int(input())
for ts in range(t):
    n,x,a,b = map(int,input().split())
    if a>b:
        a,b =b,a
    m = n-b + a-1
    if x<m:
        print(b-a+x)
    else:
        print(b-a+m)