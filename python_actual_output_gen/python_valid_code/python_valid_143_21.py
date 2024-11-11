n = int(input())
a = list(map(int, input().split()))
cnt = 0
if n == 1:
    if a[0] == 0:
       print('YES')
    else:
       print('NO')
exit()
for i in range(n):
    if a[i] == 0:
        cnt += 1
        if cnt >= 2:
            break
if cnt == 1:
    print('YES')
else:
    print('NO')
