h, r = map(int, input().split())
if h >= r: print(1)
else: print(0 if h + r == 0 else -1)
