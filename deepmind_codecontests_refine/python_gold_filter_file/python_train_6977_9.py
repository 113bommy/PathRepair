rooms = [[[0] * 10 for b in range(3)] for a in range(4)]
n = int(input())
for _ in range(n):
    b, f, r, v = map(int, input().split())
    rooms[b - 1][f - 1][r - 1] += v

for i in range(4):
    for j in range(3):
        print(' ' + ' '.join(map(str, rooms[i][j])))
    if i < 3:
        print('#' * 20)