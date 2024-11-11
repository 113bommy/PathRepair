n, a, b = [int(i) for i in input().split()]
s = [int(i) for i in input().split()]
vl = s[0]
s = s[1:]
s.sort(reverse=True)
sm = sum(s) + vl
for i in range(len(s)):
    if (vl * a) // sm >= b:
        print(i)
        break
    sm = sm - s[i]
    if (vl * a) // sm >= b:
        print(i + 1)
        break
else:
    print(1)
