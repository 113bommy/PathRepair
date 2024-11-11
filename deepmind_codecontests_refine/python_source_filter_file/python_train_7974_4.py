from sys import stdin, stdout
import random


n,m = map(int,stdin.readline().rstrip().split())
table = []
for _ in range(n):
    table.append(list(map(int,stdin.readline().rstrip().split())))

table2 = [[0]*n for _ in range(m)]
for i in range(n):
    for j in range(m):
        table2[j][i] = table[i][j]

totalSets = 0
for i in range(n):
    if sum(table[i])>1:
        totalSets+=(2**sum(table[i]))-1-sum(table[i])
    if sum(table[i])<m-1:
        totalSets+=(2**(m-sum(table[i])))-1-(m-sum(table[i]))
    
for i in range(m):
    if sum(table2[i])>1:
        totalSets+=(2**sum(table2[i]))-1-sum(table2[i])
    if sum(table2[i])<n-1:
        totalSets+=(2**(n-sum(table2[i])))-1-(m-sum(table2[i]))

totalSets+=(n*m)

print(totalSets)
