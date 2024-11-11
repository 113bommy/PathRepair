m = list(map(int, input().split()))

s = sum(m)

if not s % 5:
    print(s // 5)
else:
    print(-1)
