# https://codeforces.com/problemset/problem/1427/A
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    tot = sum(a)
    if tot == 0:
        print("NO")
    elif tot < 0:
        print("YES")
        print(sorted(a))
    else:
        print("YES")
        print(sorted(a, reverse=True))

