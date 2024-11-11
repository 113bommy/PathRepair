x0, y0, ax, ay, bx, by = list(map(int, input().split()))

xs, ys, t = list(map(int, input().split()))


r = []

for i in range(50):
    r.append((x0, y0))
    x0 = ax * x0 + bx
    y0 = ay * y0 + by

ans = 0

def distance(l, r):
    return abs(l[0] - r[0]) + abs(l[1] - r[1])

init = (xs, ys)

for i in range(len(r)):
    d = distance(r[i], init)
    if d <= t:
        ans = max(ans, 1)
        
        cd = d
        add = 0
        now = 1
        for left in range(i - 1, -1, -1):
            cd += distance(r[left], r[left + 1])
            add += distance(r[left], r[left + 1])
            now += 1
            if cd <= t:
                ans = max(ans, now)

                maybe_cd = cd + add
                maybe_now = now 
                for right in range(i + 1, len(r)):
                    maybe_cd += distance(r[right], r[right - 1])
                    maybe_now += 1
                    if maybe_cd <= t:
                        ans = max(ans, maybe_now)
                    else:
                        break
            else:
                break

        cd = d
        add = 0
        now = 1
        for right in range(i + 1, len(r)):
            cd += distance(r[right], r[right - 1])
            add += distance(r[right], r[right - 1])
            now += 1
            if cd <= t:
                ans = max(ans, now)

                maybe_cd = cd + add
                maybe_now = now 
                for left in range(i - 1, -1, -1):
                    maybe_cd += distance(r[left], r[left + 1])
                    maybe_now += 1
                    if maybe_cd <= t:
                        ans = max(ans, maybe_now)
                    else:
                        break
            else:
                break

print(ans)
