n = int(input())
cost = [int(i) for i in input().split()]
strings = []
for i in range(n):
    s = input()
    strings += [[s, i, 0], [s[::-1], i, cost[i]]]
strings.sort()

costof = [10e14+1 for _ in range(n)]+[0]

i = n*2 - 1

while (i >= 0):
    strings[i][2] += costof[strings[i][1] + 1]
    costof[strings[i][1]] = min(costof[strings[i][1]], strings[i][2])
    i -= 1

if (costof[0] > 10e14): print(-1)
else: print(costof[0])
    
