n, m = [int(i) for i in input().split()]
answer = []
individual = []
points = []
mode = [0]*m
total = 0
for i in range(n):
    answer.append(input())
points = [int(p) for p in input().split()]
for i in range(m):
    ans = ''
    for j in range(len(answer)):
        ans += answer[j][i]
    individual.append(sorted(ans))
if m == 1:
    print(sum(points))
    exit()
for i in range(len(individual)):
    counter = 1
    for j in range(1, len(individual[i])):
        if individual[i][j] == individual[i][j-1]:
            counter += 1
        else:
            counter = 1
        mode[i] = max(mode[i], counter)
for i in range(len(mode)):
    total += mode[i]*points[i]
print(total)