dic = {}
h, w, d = map(int, input().split())
lis = [list(input().split()) for _ in range(h)]
for i in range(h):
    for j in range(w):
        dic[int(lis[i][j])] = (i, j)
n = h * w
su = [0] * (n + 1)
for k in range(1, n - d + 1):
    x = dic[k + d][0] - dic[k][0]
    y = dic[k + d][1] - dic[k][1]
    su[k + d] = su[k] + abs(x) + abs(y)

q = int(input())
for i in range(q):
    s, g = map(int, input().split())
    print(su[g] - su[s])
