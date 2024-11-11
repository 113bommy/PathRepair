a, b, c = map(int, input().split())
if (a + b + c) < 2 * max(a, b, c) or (a + b + c) % 2: print('Imposible')
else: print((a + b - c) // 2, (b + c - a) // 2, (a + c - b) // 2)