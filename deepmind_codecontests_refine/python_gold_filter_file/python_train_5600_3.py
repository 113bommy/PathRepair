

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

INF = 1 << 19

"""
・dp[bit][s]
ビットに1が立っているカードはソートされて左から並んでいる。
そのとき最後の値をsにするのに必要な最小操作回数


"""
# 1 <= A,B <= 50, bitの立ち方が 0...0 ~ 1...1 の2**N
dp = [[INF for _ in range(50 + 1)] for _ in range((1 << N))]
# 0枚選んでいて右端が0は何もしてないのでコスト0
dp[0][0] = 0

for bit in range(1 << N):
    # 現在見ているbit列にいくつ1が立っているか＝カードを何枚既に選んで並べているか
    num_used = bin(bit).count("1")
    
    # bitで１が立っていない＝まだ使われていないカードがどこにあるか
    idx = num_used
    remaining = []
    for i in range(N):
        if not (bit & (1 << i)):
            # 一つ目が初期位置、二つ目は、bitで１が立っているやつらを左に寄せた時にどの位置にいるか
            remaining.append((i, idx))
            idx += 1

    for s in range(51):
        # bitの集合かつ、その右端にsの状態が作れないならスキップ
        if dp[bit][s] >= INF:
            continue

        for ini, curr in remaining:
            """
            ini  : initial position
            curr : current position
            現時点でnum_used-1のインデックスまでカードがソートされて並んでいる
            最初iniの位置にあったカードを最後尾に並べることを考える
            """
            num = A[ini] if abs(ini - num_used) % 2 == 0 else B[ini]

            """
            numが並んでるカードの最後尾より大きければ最後尾につける
            """
            if num >= s:
                # 元の集合と、iniの位置だけ１が立ってるものの論理和で、追加した状態を表す
                # その場合の最小コストは、既に求まっているもの or 新たにnum_usedの位置にiniのカードをあてたとき　の小さいほう
                dp[bit | (1 << ini)][num] = min(dp[bit | (1 << ini)][num], dp[bit][s] + abs(num_used - curr))



# 全てのbitに1が立っている（全て並べ切った）時の最小コストが答え
ans = min(dp[-1][s] for s in range(51))

print(ans if ans < INF else -1)
