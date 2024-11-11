from math import ceil

k, d, t = list(map(int, input().split()))

a = ceil(k/d)

t_on = k
t_off = d * a - k

ans = 0.

progress = t_on/t + t_off/2/t

k2 = int(1/progress)
ans += float(k2) * float((t_on + t_off))

progress *= k2

rem = 1 - progress
if t_on / t >= float(rem):
    ans += rem * t
else:
    ans += t_on
    rem2 = rem - t_on / t
    ans += 2 * rem2
print(ans)