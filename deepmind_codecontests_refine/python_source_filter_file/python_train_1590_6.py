import sys

input = sys.stdin.readline

n = int(input())
cost, ans = 0, 1000000000000000000000000
a = [int(x) for x in input().split()]
a.sort()
l, r = -1, -1
if n > 32:
    l, r = 1, 1
elif 32 >= n > 20:
    l, r = 1, 2
elif 20 >= n >= 15:
    l, r = 1, 10
elif 15 > n >= 10:
    l, r = 1, 14
elif 10 > n >= 7:
    l, r = 1, 25
elif 7 > n >= 5:
    l, r = 1, 100
elif n == 4:
    l, r = 1, 200
elif n == 3:
    l, r = 1, 100000
elif n == 2:
    l, r = 1, 10000000
elif n == 1:
    l, r = 1, 10000000

for q in range(l, r + 1):
    cost = 0
    for i in range(n):
        cost += abs(a[i] - q ** i)
    ans = min(ans, cost)

print(ans)
