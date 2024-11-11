a, b = map(int, input().split())
if not a and b: print('Impossible')
elif not b: print(a)
else: print(a + max(b - a, 0), a + b - 1)