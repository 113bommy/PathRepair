# https://codeforces.com/contest/1438/problem/D

"""
    Solution -

"""

n = int(input())
a = list(map(int, input().split()))

X = 0

for i in a:
    X = X^i 

if n % 2 == 0 and X != 0:
    print("NO")
else:
    print("Yes")
    ans = []
    for i in range(3, n+1, 2):
        ans.append([i-1, i-1, i])
    for i in range(2, n, 2):
        ans.append([i-1, i, n])
    print(len(ans))
    for i in ans:
        print(*i)