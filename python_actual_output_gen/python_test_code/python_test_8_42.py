# https://codeforces.com/problemset/problem/1065/A

for _ in range(int(input())):
    s, a, b, c = map(int, input().split())
    chocolates = s // c
    if chocolates > a:
        print(chocolates + b * (chocolates // a))
    else:
        print(chocolates)
