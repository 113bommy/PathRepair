x, a, b = map(int, input().split())
if a-b <= 0: print("delicious")
elif a-b <= x: print("safe")
else: print("dangerous")