n, k = map(int, input().split())
ans = []
for i in range(n):
    for j in range(n):
        if (i + j) % 2 == 0 and k > 0:
            ans.append('L')
            k -= 1
        else:
            ans.append('S')
if k == 0:
    print('YES')
    for i in range(len(ans)):
        if (i + 1) % n == 0:
            print(ans[i])
        else:
            print(ans[i], end='')
else:
    print('NO')

