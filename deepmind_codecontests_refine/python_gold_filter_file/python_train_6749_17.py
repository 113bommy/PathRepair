N = int(input())
red = [list(map(int, input().split())) for _ in range(N)]
blue = [list(map(int, input().split())) for _ in range(N)]
ans = 0
red = sorted(red, key = lambda x:x[1] * -1)
blue = sorted(blue)
for b in blue:
	for r in red:
		if b[0] > r[0] and b[1] > r[1]:
			ans += 1
			red.remove(r)
			break
print(ans)
