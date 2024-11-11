n, a, b = map(int, input().split())
if n > a*b:
    print(-1)
    exit()
dd = 1
cur = 1
for j in range(a):
    s = " ".join([str(i) if i <= n else "0" for i in range(cur, cur + b)])[::dd]
    print(s)
    cur += b    
    dd *= 1 if b%2 == 1 else -1

