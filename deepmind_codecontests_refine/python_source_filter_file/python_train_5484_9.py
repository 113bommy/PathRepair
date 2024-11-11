MAX_WORD = '1' * 10000
n = int(input())
a = list()
for i in range(n):
    x = input()
    a.append(x)
a.sort()
busy = list(False for _ in range(n))
busy[0] = True
ans = list([a[0],])
check = True
i = 0
while i < n and check:
    check = False
    res = MAX_WORD
    for j in range(n):
        if a[j].find(ans[i]) != -1 and len(a[j]) < len(res) and not busy[j]:
            res = a[j]
    for j in range(n):
        if a[j] == res and not busy[j]:
            busy[j] = True
            break
    if res != MAX_WORD:
        ans.append(res)
        check = True
    i += 1
if len(ans) == n:
    print('YES')
    for i in range(n):
        print(ans[i])
else:
    print('NO')
