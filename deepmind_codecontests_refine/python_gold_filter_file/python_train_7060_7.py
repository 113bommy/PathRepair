from itertools import accumulate

# bisectはどっちでも（どちらに等号をつけても）うまくいくっぽい
from bisect import bisect_right, bisect_left

N = int(input())
A = list(map(int, input().split()))

# 累積和を前計算
cumsum = list(accumulate(A))
cumsum.insert(0, 0)  # out of index 対策


ans = float('inf')
# 真ん中を全探索
for i in range(2, N-1):  # 左側は最低2つ残さなきゃいけないから2から(0もあるので）、右も同じ理由でN-1
    # 左の真ん中
    Lmid = cumsum[i] / 2

    # 左真ん中がどこに入るべきか
    Lx = bisect_left(cumsum, Lmid)

    # Lxまで取るのか、Lx-1まで取るのか（どこまで取ると望ましい値Lmidに近づくのか）
    # 左側がLmidに近づくと右側もLmidに近づく→差の絶対値が0に近づく
    if abs(cumsum[Lx-1] - Lmid) < abs(cumsum[Lx] - Lmid):
        Lx -= 1


    # 右側処理（基本は左と同じ）
    Rmid = (cumsum[N] + cumsum[i]) / 2  # 3分探索に要領でcumsum[N]を加えてやる
    Rx = bisect_left(cumsum, Rmid)
    # 超えるべきか超えないべきか
    if abs(cumsum[Rx-1] - Rmid) < abs(cumsum[Rx] - Rmid):
        Rx -= 1


    # 左からLx個の和
    P = cumsum[Lx]

    # Lx番目+1から真ん中区切りiまでの和
    Q = cumsum[i]-cumsum[Lx]

    # 真ん中区切りのi+1番目からRx番目までの和
    R = cumsum[Rx]-cumsum[i]

    # Rx+1番目から最後まで
    S = cumsum[N]-cumsum[Rx]
    
    ans = min(ans, max(P, Q, R, S) - min(P, Q, R, S))

print(ans)
