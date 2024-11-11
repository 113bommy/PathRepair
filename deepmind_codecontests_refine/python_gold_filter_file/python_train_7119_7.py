from datetime import date
a, b, c = map(int, input().split(":"))
d, e, f = map(int, input().split(":"))
tmp1 = date(a, b, c)
tmp2 = date(d, e, f)
ans = tmp2 - tmp1
print(abs(ans.days))