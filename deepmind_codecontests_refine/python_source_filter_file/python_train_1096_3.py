n = int(input())
l = list(map(int, input().split()))
mx = l.index(max(l))
mn = l.index(min(l))
if mn > mx:
    mn, mx = mx, mn
print(max(mx, n - mn) - 1)