"""https://codeforces.com/contest/1092/problem/A"""
alpha = 'abcdefghijklmnopqrstuvwxyz'
for _ in range(int(input())):
    n, k = tuple(map(int,input().split()))
    s = alpha[:k] + 'a'*(n-k)
    print(s)