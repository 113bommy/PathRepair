def main():
    import sys
    input = sys.stdin.readline

    sys.setrecursionlimit(10 ** 8)

    MOD = 10 ** 9 + 7

    N = int(input())
    G = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        x, y = map(int, input().split())
        G[x].append(y)
        G[y].append(x)

    # B = [0] * (N + 1) #自分自身が黒色の時
    # W = [0] * (N + 1) #自分自身が白色の時
    # T = [0] * (N + 1) #B + W
    C = [False] * (N + 1) #訪れたことのチェック

    def calc(x): #xからの動き方を調べる
        C[x] = True

        b = 1
        w = 1

        for next_ in G[x]:
            if C[next_]:
                continue
            tmp_b, tmp_w = calc(next_)
            b = (b * tmp_b) % MOD
            w = (w * tmp_w) % MOD
        # B[x] = b
        # W[x] = w
        return w, (b + w) % MOD

    tmp, ans = calc(1)
    print (ans)
    # print ((B[1] + W[1]) % MOD)

if __name__ == '__main__':
    main()