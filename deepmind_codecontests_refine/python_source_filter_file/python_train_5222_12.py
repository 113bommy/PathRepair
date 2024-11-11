# https://codeforces.com/problemset/problem/1162/A

n, h, m = map(int, input().split())

houses = [10] * n

for i in range(m):
    l, r, x = map(int, input().split())
    for k in range(l - 1, r):

        houses[k] = min(houses[k], x)


ans = 0

for i in houses:
    ans += i ** 2
print(ans)


