t = int(input())
for i in range(t):
    n,m = map(int, input().split())
    l = list(map(int, input().split()))
    s = sum(l)
    if(s>m):
        print(s)
    else:
        print(m)

