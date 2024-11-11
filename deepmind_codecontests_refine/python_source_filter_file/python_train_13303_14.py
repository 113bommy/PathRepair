
t1, t2 = map(int, input().split())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

d1 = t1 * (a1 - b1)
d2 = t2 * (a2 - b2)

if d1 > 0:
    d1 *= -1
    d2 *= -1

if d1 + d2 == 0:
    print("infinity")
elif d1 + d2 < 0:
    print(0)
else:
    cnt = -d1 // (d1 + d2)
    t = -d1 % (d1 + d2)
    ans = 1 + 2 * cnt + int(t == 0)
    print(ans)
