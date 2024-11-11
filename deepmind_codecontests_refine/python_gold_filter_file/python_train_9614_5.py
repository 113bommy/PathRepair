n = int(input())
p = [0] * (n + 1)
p = list(map(int, input().split()))
a, b, c, d, e = map(int, input().split())
points = int(0)
cnt = [0] * 5
for i in range(0, n):
    points = points + p[i]
    while 1:
        if points >= e:
            val = (points / e)
            val = int(val)
            points -= e * val
            cnt[4] += val
        elif points >= d:
            val = (points / d)
            val = int(val)
            points -= d * val
            cnt[3] += val
        elif points >= c:
            val = (points / c)
            val = int(val)
            points -= c * val
            cnt[2] += val
        elif points >= b:
            val = (points / b)
            val = int(val)
            points -= b * val
            cnt[1] += val
        elif points >= a:
            val = (points / a)
            val= int(val)
            points -= a * val
            cnt[0] += val
        else:
            break

ans = " ".join(map(str,cnt))
print(ans)
print(points)
