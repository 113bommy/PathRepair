resident = [[[0] * 10 for _ in range(3)] for _ in range(4)]
for _ in range(int(input())):
    b, f, r, v = map(int, input().split())
    resident[b - 1][f - 1][r - 1] += v
for b in range(4):
    for f in range(3):
        print(" ".join(map(str, resident[b][f])))
    if b < 3:
        print("####################")

