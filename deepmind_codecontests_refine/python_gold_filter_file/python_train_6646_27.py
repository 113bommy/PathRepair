from collections import Counter
from operator import itemgetter
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
As = [list(map(int, input().split())) for _ in range(N)]
indices = [0 for i in range(N)] 
#i+1 th person attends his (indices[i]+1) th best favorite sport.

min_turnout = N
canceled_sports = set()
for _ in range(M-1):
    popular_sport, turnout = max(Counter(As[i][indices[i]] for i in range(N)).items(), key = itemgetter(1))
    min_turnout = min(min_turnout, turnout)
    canceled_sports.add(popular_sport)
    for i in range(N):
        while As[i][indices[i]] in canceled_sports:
            indices[i] += 1

print(min_turnout)

