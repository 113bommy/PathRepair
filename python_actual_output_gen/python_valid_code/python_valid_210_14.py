# https://codeforces.com/problemset/problem/46/A

n = int(input())

a = 1
for i in range(1, n):
    a += i
    print(a % n, end=" ")

