A, B = map(int, input().split())

ans = [['#'] * 100 for _ in range(50)] + [['.'] * 100 for _ in range(50)]
# print(ans)

i, j = 0, 1
for _ in range(A-1):
    ans[i][j] = '.'
    j += 2
    if j == 101:
        i += 2
        j = 1

i, j = 51, 1
for _ in range(B-1):
    ans[i][j] = '#'
    j += 2
    if j == 101:
        i += 2
        j = 1

print('100 100')
for a in ans:
    print(a)
