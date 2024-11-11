# https://codeforces.com/problemset/problem/678/A

n, k = map(int, input().split())

x = n % k

if x != 0:
    print(n + k - x)
else:
    print(n + k)
