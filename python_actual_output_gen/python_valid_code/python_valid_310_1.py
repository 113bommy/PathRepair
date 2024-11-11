n = int(input())
a = [int(i) for i in input().split()]
t = [[] for i in range(n + 1)]
t[0] = [0, 0]
for i in range(2 * n):
    t[a[i]].append(i)
su = 0
print(t)
for i in range(1, n + 1):
    su += abs(t[i][0] - t[i - 1][0]) + abs(t[i][1] - t[i - 1][1])
print(su)