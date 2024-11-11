L = int(input())
ans = []

# 頂点数はbitの長さ
N = len(bin(L)[2:])

# 頂点間に0の辺と2**iの辺を張る
for i in range(N - 1)[::-1]:
    ans.append([i + 1, i + 2, 2 ** (N - i - 2)])
    ans.append([i + 1, i + 2, 0])

# 表現できてないパスの個数
need = L - (2 ** (N - 1))

# 表現できてないコスト（大きい順）
cost = list(range(2 ** (N - 1), 2 ** (N -1) + need))

# コストのリスト上を移動するマーカー
marker = 0

# どこにバイパスを張るか
bit = bin(need)[2:]

# バイパスを張っていく
for i in range(len(bit)):
    if bit[i] != "1":
        continue

    # 辺を追加
    ans.append([1, N - i, cost[marker]])

    # マーカーを進める
    marker += 2 ** i

print(N, len(ans))
for a in ans:
    print(" ".join(map(str, a)))
