import sys
input = sys.stdin.readline

task = []
N = int(input())
for _ in range(N):
    task.append(list(map(int, input().split())))

task.sort()
#print(task)
ans = 0

task_minmax = [None] * (N+1)
task_minmax[N] = [0, 10**9]
for i in range(N-1, -1, -1):
    task_minmax[i] = [max(task_minmax[i+1][0], task[i][0]), min(task_minmax[i+1][1], task[i][1])]

mini = 0
maxi = 10**9

#print(task_minmax)

for i in range(N-1):
    temp = 0
    if i != 0:
        ans = max(ans, max(0, min(maxi, task_minmax[i+1][1]) - max(mini, task_minmax[i+1][0]) + 1) + (task[i][1] - task[i][0]) + 1)

    mini = max(task[i][0], mini)
    maxi = min(task[i][1], maxi)

    temp += maxi - mini + 1
    temp += max(task_minmax[i+1][1] - task_minmax[i+1][0] + 1, 0)

    ans = max(temp, ans)

print(ans)
