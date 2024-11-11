n, m, v, p = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(reverse=True)
thr = arr[p - 1]

ok, ng = 0, n

while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    # midに全力投票した時のスコア
    x = arr[mid] + m
    # 残りの投票数
    rest = m * (v - 1)

    # 全力投票で届かない場合は探索を続行
    if x < thr:
        ng = mid
        continue

    # 全力投票で届く場合、残りの票を上手く処理できるか
    for i, a in enumerate(arr):
        # idxがp未満の場合は最大まで積める
        if i < p and arr[i] > thr:
            rest -= m
        elif i == mid:
            continue
        # idxがpより後ろの場合はmかx-aまで積める
        else:
            rest -= min(m, x - a)

    # 消化しきれていれば勝ち、そうでなければ負け
    if rest <= 0:
        ok = mid
    else:
        ng = mid

print(ok + 1)