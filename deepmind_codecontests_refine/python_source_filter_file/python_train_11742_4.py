import sys
def input(): return sys.stdin.readline().strip()
sys.setrecursionlimit(10 ** 9)

def main():
    N = int(input())
    repn = [[] for _ in range(N)]
    for i in range(N - 1):
        a, b = map(int, input().split())
        repn[a - 1].append((b - 1, i))
        repn[b - 1].append((a - 1, i)) # (to, id)
    M = int(input())

    """
    一般に頂点vと頂点tvの間の辺を出力する再帰関数dfsを用意する。
    頂点vからdfsしたとして、頂点tvにたどり着いたところから再帰がスタート。
    まず辺を格納するedgesを空にして、dfs(e[0], tv, v)が成り立つなら
    v-...-e-tvのパスが確定しているのでeとtvを繋ぐパスe[1]をedgeに加える。
    これを順に再帰で繰り返す。
    """
    edges = []
    def dfs(v, tv, p=-1):
        if v == tv:
            edges.clear()
            return True
        for e in repn[v]:
            if e[0] == p:
                continue
            if dfs(e[0], tv, v):
                edges.append(e[1])
                return True
        return False

    """
    M個の各条件に対してパスの情報を記録するのにはビットを用いると良い。
    具体的にはedgesetと言うM個の整数配列を用意して、i番目のクエリに対して
    uiとviを繋ぐ辺が[ej1,ej2,...,ejk]だったとすると、これはedgeset[i]の
    j1,j2,...,jk番目のビットを立てて保持しておく。
    　→　あとで包除原理する際に楽。
    """

    edgeset = [0] * M
    for i in range(M):
        u, v = map(int, input().split())
        dfs(u - 1, v - 1)
        for id in edges:
            edgeset[i] |= 1 << id

    """
    ここから包除原理。M個の条件のうちどの条件だけを考慮するかは(1 << M)通りの選択があることに注意。
    """

    ans = 0
    for i in range(1 << M):
        mask = 0
        for j in range(M):
            if (i >> j) & 1:
                mask |= edgeset[j]
        white = bin(mask).count("1")
        val = 1 << (N - 1 - white)
        if bin(i).count("1") % 2 == 0:
            ans += val
        else:
            ans -= val
    print(ans)

if __name__ == "__main__":
    main()
