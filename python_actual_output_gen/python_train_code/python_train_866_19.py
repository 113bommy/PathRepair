# https://codeforces.com/problemset/problem/746/A

a = int(input())
b = int(input())
c = int(input())

ans = min(a // 1, b // 2, c // 4)

print(a * ans + b * ans + c * ans)
