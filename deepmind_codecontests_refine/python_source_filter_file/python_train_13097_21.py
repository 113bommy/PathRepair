N = int(input())
abc = [[int(j) for j in input().split()] for i in range(n)]
dp = [[0] * 3]
for day in range(N):
    dp += [[max([dp[-1][p] + abc[day][n] for p in range(3) if p != n]) for n in range(3)]]
print(max(dp[-1]))