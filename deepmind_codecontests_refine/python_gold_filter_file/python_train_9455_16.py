n = int(input())
a = list(map(int, input().split()))
m = max(a)
ans = ' '.join((
    str(m),
    str(max(sorted(a), key=lambda x: min(x, m - x)))
))
print(ans)