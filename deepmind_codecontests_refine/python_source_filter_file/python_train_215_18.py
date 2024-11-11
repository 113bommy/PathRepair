n, s = map(int, input().split())
a = sorted(map(int, input().split()))

n2 = n // 2

ans = sum(0 if x < s else (x - s) for x in a[:n2])
ans += abs(a[n2] - s)
ans += sum(0 if x > s else (s - x) for x in a[-n2:])
print(ans)
