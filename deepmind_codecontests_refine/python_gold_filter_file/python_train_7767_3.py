'''
codeforces.com/problemset/problem/859/C
author: latesum
'''
n = int(input())
v = list(map(int,input().split()))
v.reverse()
ans = [0, 0]
for i in range(n):
    if ans[1] + v[i] > ans[0]:
        t = ans[1] + v[i]
        ans[1] = ans[0]
        ans[0] = t
    else:
        ans[1] += v[i]
print(ans[1], ans[0])
