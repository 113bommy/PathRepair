l = [[[0] * 10 for _ in range(3)] for _ in range(4)]
for _ in range(int(input())):
    b, f, r, v = map(int, input().split())
    l[b - 1][f - 1][r - 1] += v

for x in range(4):
    for y in range(3):
        print()
        print(*l[x][y])
    if x != 3:
        print("####################")