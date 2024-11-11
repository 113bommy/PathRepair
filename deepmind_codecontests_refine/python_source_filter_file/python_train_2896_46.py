N, K = map(int, input().split())
vA = list(map(int, input().split()))

# 累積和
vC = [0,]
for a in vA:
    vC.append(a + vC[-1])

# 部分列の和 (美しさ)
vB = []
for i in range(len(vC)):
    vB.extend([vC[i+j+1] - vC[i] for j in range(N-i)])

# 最上位bitが何桁目かを取得
blenB = max(vB).bit_length()

# K個に満たない上位bitは最終的に残らないので除去する
# 上からK個以上あるものを決めていく
x = 0
for i in reversed(range(1, blenB+1)):
    x_new = x + (1<<i)
    if sum((x_new & b) == x_new for b in vB) >= K:
        x = x_new

print(x)
