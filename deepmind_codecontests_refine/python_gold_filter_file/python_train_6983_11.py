x = [[[0 for k in range(10)]for j in range(3)]for i in range(4)]
n = int(input())
for i in range(n):
    [b, f, r, v] = map(int, input().split())
    x[b-1][f-1][r-1] += v

for b in range(4):
    for f in range(3):
        tmp = list(map(str, x[b][f]))
        print(" "+" ".join(tmp))
    if b!=3:
        print("#"*20)