residents = [[[0] * 11 for i in range(4)] for j in range(5)]
N = int(input())
for _i in range(N):
    b, f, r, v = map(int, input().split())
    residents[b][f][r] += v
for i in range(1, 5):
    for j in range(1, 4):
        print(' ' + ' '.join(map(str, residents[i][j][1:])))
    if not i == 4:
        print(''.join(['#'] * 20))
