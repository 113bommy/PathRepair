h, w = map(int, input().split())
ans = 0
for i in range(h):
	a = input()
	ans += a.count("#")
if ans == h + w - 1:
	print("Possible")
else:
	print("Impossible")