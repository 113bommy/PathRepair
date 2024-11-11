a, b, c, d = map(int, input().split())
t = [a, b, c]
t.sort()
ans = 0
a = t[0]
b = t[1]
c = t[2]
if b - a < d and c - b < d:
    ans += 2 * (d - (b - a)) + d - (c - b)
elif b - a >=d and c - b < d:
    ans += d - (c-b)
elif b-a<d and c-b>=d:
    ans += d-(b-a)
else:
    ans = 0
print(ans)