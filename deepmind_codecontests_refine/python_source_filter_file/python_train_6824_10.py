n = int(input())
c = list(map(int, input().split()))
inf = 10 ** 12
d = [[inf] * 2 for i in range(n)]
prev_s = input().rstrip()
d[0][0] = 0
d[0][1] = c[0]
flag = 0
for i in range(1, n):
    s = input().rstrip()
    if s >= prev_s:
        d[i][0] = min(d[i][0], d[i - 1][0])
    if s >= prev_s[::-1]:
        d[i][0] = min(d[i][0], d[i - 1][1])
    if s[::-1] >= prev_s:
        d[i][1] = min(d[i][1], d[i - 1][0] + c[i])
    if s[::-1] >= prev_s[::-1]:
        d[i][1] = min(d[i][1], d[i - 1][1] + c[i])
    prev_s = s
    if d[i][0] >= inf and d[i][1] >= inf:
        flag = -1
        break
if flag == -1:
    print(-1)
else:
    print(min(d[n - 1][0], d[n - 1][1]))