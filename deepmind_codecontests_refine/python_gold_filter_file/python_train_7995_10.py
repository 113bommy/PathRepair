n, m = map(int, input().split())
if n >= m:
    print(0)
    exit()
x = sorted(map(int, input().split()))
l = sorted(i - j for i, j in zip(x[1:], x[:-1]))
print(sum(l[: m - n]))