import bisect  # 配列二分法
from collections import defaultdict

N = int(input())
S = [*input()]
Q = int(input())
d = defaultdict(list)

# 各アルファベットの出現場所を記録
for i, c in enumerate(S):
    d[c] += [i]

# この時点でどのアルファベットについてもソート済み
# print(d)

for _ in range(Q):
    q, y, z = input().split()

    if q == '1':
        i = int(y) - 1  # 文字の変更位置

        if S[i] == z: continue  # 同じ文字の場合は処理終了

        # 削除 O(N)
        b = bisect.bisect(d[S[i]], i)  # 2分法で i の出現位置を(log N)で探す
        d[S[i]].pop(b - 1)  # 削除

        # 追加 O(N) かかる？
        S[i] = z
        bisect.insort(d[z], i) 

    else:
        left = int(y) - 1
        right = int(z) - 1

        count = 0
        for v in d.values():
            count += 1 if bisect.bisect(v, right) - bisect.bisect_left(v, left - 1) > 0 else 0

        print(count)