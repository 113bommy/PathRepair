from sys import stdin
input = stdin.readline

n = int(input())

degree = [0 for i in range(n+1)]

for _ in range(n-1):
    i, j = [int(i) for i in input().split()]
    degree[i] += 1
    degree[j] += 1
    
res = False

for i in range(1, n+1):
    if degree[i] == 2: res = True
        
if res: print("YES")
else: print("NO")