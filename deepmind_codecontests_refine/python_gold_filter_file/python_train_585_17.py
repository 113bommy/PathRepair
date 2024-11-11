import math
k, d, t = map(int, input().split())
if k > d:
    turntime = math.ceil(k / d) * d
    turnvalue = k + (turntime - k) / 2
else:
    turntime = d
    turnvalue = k + (d - k) / 2
#print(turntime, turnvalue)
ans = t // turnvalue * turntime
t %= turnvalue
#print(ans, t)
if t <= k:
    ans += t
else:
    ans += k + (t - k) * 2
print(ans)
