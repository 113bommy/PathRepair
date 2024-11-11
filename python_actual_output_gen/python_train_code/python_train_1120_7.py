N = int(input())
ans = []
M = n + 1 * (N % 2 == 0)
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        if i + j == M:
            continue
        ans.append('{} {}'.format(i, j))
print(len(ans))
print('\n'.join(ans))