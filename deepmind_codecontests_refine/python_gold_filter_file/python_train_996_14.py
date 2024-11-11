a, b = input().split()
c, d = input().split()
a, b, c, d = int(a), int(b), int(c), int(d)

if d > b:
    a, b, c, d = c, d, a, b

d = d % c
for i in range(c):
    res = b + a*i
    if res % c == d:
        print(res)
        break
else:
    print("-1")
