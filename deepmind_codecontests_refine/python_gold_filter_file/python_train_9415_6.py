n, d = map(int, input().split())
l = list(map(int, input().split()))
s = sum(l)
if d < (n-1)*10+s:
    print(-1)
else:
    print((d-s) // 5)