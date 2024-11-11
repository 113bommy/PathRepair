(n,d) = [int(x) for x in input().split(' ')]
tt = n * "1"
t = 0
ans = -1e7
for i in range(0,d):
    xx = input()
    if xx == tt:
        t = 0
    else:
        t += 1
        ans = max(ans, t)
print(ans)