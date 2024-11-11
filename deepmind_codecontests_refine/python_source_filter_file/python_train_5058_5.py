n = int(input())
earliestFinishChess,latestStartChess = 10**12, -1
for i in range(n):
    s,f = map(int, input().split())
    earliestFinishChess = min(earliestFinishChess, f)
    latestStartChess = max(latestStartChess, s)

m = int(input())

earliestFinishProgramming, latestStartProgramming = 10*12, -1
for i in range(m):
    s,f = map(int, input().split())
    earliestFinishProgramming = min(earliestFinishProgramming, f)
    latestStartProgramming = max(latestStartProgramming, s)

print(max(0, latestStartChess - earliestFinishProgramming, latestStartProgramming - earliestFinishChess))
