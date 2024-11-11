n = int(input())
x, y = (int(a) for a in input().split())
d1 = max(x - 1, y - 1)
d2 = max(n - x, n - y)
if d1 >= d2:
    print('White')
else:
    print('Black')