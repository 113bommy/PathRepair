s = input()
t = input()
a = list(map(int, input().split()))


def exist(m):
    vis = [0] * len(s)
    for i in range(m):
        vis[a[i] - 1] = 1
    j = 0
    for i in range(len(s)):
        if vis[i] == 0:
            if s[i] == t[j]:
                j += 1
            if j == len(t):
                return 1
    return 0


l, r = 0, len(s)
while l < r:
    mid = (l + r + 1) // 2
    if exist(mid):
        l = mid
    else:
        r = mid - 1

print(l)
