
H, W, D = map(int, input().split())
A = [list(map(int, input().split())) for i in range(H)]
Q = int(input())
LR = [list(map(int, input().split())) for i in range(Q)]
d = [0] * (H*W)
num_dict = {}
y = 0
for aa in A:
    x = 0
    for a in aa:
        num_dict[a] = [x, y]
        x += 1
    y += 1

for i in range(D+1, H*W):
    d[i] = d[i-D] + abs(num_dict[i][0]-num_dict[i-D][0]) + abs(num_dict[i][1]-num_dict[i-D][1])
for l, r in LR:
    print(d[r]-d[l])
