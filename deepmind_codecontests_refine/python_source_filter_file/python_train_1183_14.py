n, k = map(int, input().split())
try:
    a = sorted(map(int, input().split()), reverse=True)[k]
    print(a, a)
except:
    print(-1)
