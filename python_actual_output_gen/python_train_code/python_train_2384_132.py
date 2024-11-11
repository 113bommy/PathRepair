def check(n,m):
    if n/m==2:
        return print("YES")
    else:
        return print("NO")


t = int(input())
for i in range(t):
    n,m = map(int, input().split())
    check(n, m)
