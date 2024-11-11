# AOJ 1575: Product Sale Lines
# Python3 2018.7.13 bal4u

W, H = map(int, input().split())
N = int(input())
P = list(map(int, input().split()))
ans = x = y = 0
for p in P:
	if p == 0: x += 1
	else: y += 1
	if x < W-1:
		if x == y: ans += 1
	elif x == W-1: pass
	elif x < W+H-2:
		if x == y+2: ans += 1
	elif x == W+H-2: pass
	else:
		if x == y+4: ans += 1
print(ans)
