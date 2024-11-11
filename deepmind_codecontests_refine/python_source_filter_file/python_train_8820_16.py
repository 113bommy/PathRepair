# http://codeforces.com/contest/992/problem/C

x, k = map(int, input().split())

md = 10 ** 9 + 7

res = x * pow(2, k + 1, md) - pow(2, k, md) + 1 if x > 0 else 0
print(res)
