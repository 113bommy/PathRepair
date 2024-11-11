s, x1, x2 = map(float, input().split())
t1, t2 = map(float, input().split())
p, d = map(int, input().split())
ans = abs(x1 - x2) * t2
if (x2 > x1):
    d *= -1
    p = s - p
    x1 = s - x1
    x2 = s - x2
    
if (d == -1):
    if (p < x1):
        ans = min(ans, (p + s + s - x2) * t1)
    else:
        ans = min(ans, (p - x2) * t1)
else:
    ans = min(ans, (s - p + s - x2) * t1)

print(ans)