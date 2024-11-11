a = int(input())
b = [int(x) for x in input().split()]
c = b.index(max(b))
d = list(reversed(b)).index(min(b))
if (c > (a - d)) or (a == 2 and c != 0):
    print(c+d-1)
else:
    print(c+d)
