n, c = map(int, input().split())
sushi = [list(map(int, input().split())) for _ in range(n)]
clock = [[0, 0] for _ in range(n)]
anticlock = [[0, 0] for _ in range(n)]

max_clock = max(sushi[0][1] - sushi[0][0], 0)
clock[0] = [sushi[0][1] - sushi[0][0], max_clock]
for i in range(1, n):
	clock[i][0] = clock[i-1][0] + sushi[i][1] - (sushi[i][0] - sushi[i-1][0])
	max_clock = max(max_clock, clock[i][0])
	clock[i][1] = max_clock

max_anti = max(sushi[-1][1] - (c - sushi[-1][0]), 0)
anticlock[0] = [sushi[-1][1] - (c - sushi[-1][0]), max_anti]
for i in range(1, n):
	anticlock[i][0] = anticlock[i-1][0] + sushi[-(i+1)][1] - (sushi[-i][0] - sushi[-(i+1)][0])
	max_anti = max(max_anti, anticlock[i][0])
	anticlock[i][1] = max_anti

ans_clock = 0
ans_anti = 0

for i in range(n - 1):
	if clock[i][0] - sushi[i][0] + anticlock[n - 2 - i][1] > ans_clock:
		ans_clock = clock[i][0] - sushi[0][0] + anticlock[n - 2 - i][1]
	if anticlock[i][0] - (c - sushi[-(i+1)][0]) + clock[n - 2 - i][1] > ans_anti:
		ans_anti = anticlock[i][0] - (c - sushi[-(i+1)][0]) + clock[n - 2 - i][1]

print(max(ans_clock, ans_anti, clock[-1][1], anticlock[-1][1]))