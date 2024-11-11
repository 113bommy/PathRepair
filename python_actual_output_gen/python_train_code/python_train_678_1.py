n = int(input())
l = list(map(int, input().split()))
l.sort()
a = l[0]
b = l[1]
c = l[2]
if a < b < c:
    print(l.count(c))
elif a < b and b == c:
    x = l.count(b)
    print(b * (b - 1) // 2)
elif a == b and b < c:
    print(l.count(c))
else:
    x = l.count(a)
    print(a * (a - 1) * (a - 2) // 6)