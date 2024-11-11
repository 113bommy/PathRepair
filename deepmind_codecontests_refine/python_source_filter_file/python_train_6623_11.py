# https://codeforces.com/problemset/problem/873/A

n, k, x = map(int, input().split())

times = tuple(map(int, input().split()))

print(sum(times[:n - 2]) + k * x)
