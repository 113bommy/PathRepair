import sys
input = sys.stdin.readline

t = int(input())

n = list(map(int, input().split()))

maxx = 0

for i in range(t):
    for j in range(i,t):
        for k in range(j,t):
            maxx = max(maxx, n[i]|n[j]|n[k])

            
print(maxx)