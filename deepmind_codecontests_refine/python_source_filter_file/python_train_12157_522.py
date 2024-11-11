d, t, s = map(int, input().split())
ans = d/s
print('Yes' if ans < float(t) else "No"