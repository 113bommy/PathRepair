n, x, y = [int(s) for s in input().split(' ')]
a = input()
z = len([t for t in a.split('1') if t])
ans = min(z * y, y + (z - 1) * x)
print(ans)