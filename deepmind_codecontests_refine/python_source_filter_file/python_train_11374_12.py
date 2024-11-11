# started 5.10
# 
from sys import setrecursionlimit, stdin
import math

setrecursionlimit( 10 ** 5)
readline = stdin.readline

# observe nice problem

for _ in range(int(readline().rstrip())):
    n,m = map(int, readline().split())

    temp_list = []
    grid = [ list(map(int, readline().split())) for _ in range(n)]
    countzero, countone = [0]*(n+m-1), [0]*(n+m-1)
    ans = 0

    for i in range(n):
        for j in range(m):
            if not grid[i][j]:
                countzero[i+j]+=1
            else:
                countone[i+j] +=1
    
    if (n+m)%2 == 0:
        v = (n-1 + m-1)//2
    else:
        v = (n-1 + m-1 + 1)//2

    for i in range(v):
        # ignore the middle one
        zeroes = countzero[i] + countzero[n-1 + m-1 -i]
        ones = countone[i] + countone[n-1 + m-1 -i]

        ans += min(zeroes, ones)
    
    #print("ANS", ans)


