n, m, k = map(int, input().split())
N = (k - 1) // (2 * m) + 1
print(N, (k - (N - 1) * 2 * m + 1) // 2, end = ' ')
if k % 1 == 0:
    print('R')
else:
    print('L')