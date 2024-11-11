n, a, b = map(int, input().split())
line = list(map(int, input().split()))
cnt = 0
tr = False
for i in range(n // 2):
    #print(line[i], line[n - i - 1])
    if line[i] == 2 and line[n - i - 1] == 0 or line[n - i - 1] == 2 and line[i] == 0:
        cnt += a
    elif line[i] == 2 and line[n - i - 1] == 1 or line[n - i - 1] == 2 and line[i] == 1:
        cnt += b
    elif line[i] == 2 and line[n - i - 1] == 2:
        cnt += min(a, b) * 2
    elif line[i] != line[n - i - 1]:
        tr = True
if n % 2 != 0:
    if line[n // 2] == 2:
        cnt += min(a, b)
if tr:
    print(-1)
else:
    print(cnt)
    