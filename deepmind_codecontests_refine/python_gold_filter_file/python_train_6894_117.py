t = int(input())
while t>0:
    t = t-1
    n,m = map(int,input().split())
    if n%m == 0:
        print("YES")
    else:
        print("NO")