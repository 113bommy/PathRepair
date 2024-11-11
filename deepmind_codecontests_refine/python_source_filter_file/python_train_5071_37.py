n, B = list(map(int, input().split()))
a = list(map(int, input().split()))

res = []
if a[0] % 2 == 0:
    bal = 1
else:
    bal = -1
for i in range(1, n):
    if bal == 0:
        res.append(a[i] - a[i - 1])
    if a[i] % 2 == 0:
        bal += 1
    else:
        bal -= 1

res.sort()
cnt = 0
ans = 0

while(cnt <= B):
    if ans == len(res):
        ans += 1
        break
    cnt += res[ans]
    ans += 1

print(ans - 1)