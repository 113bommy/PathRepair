def f_must_be_rectangular(N, Positions):
    # 参考: https://atcoder.jp/contests/abc131/submissions/6086451
    # x軸, y軸をまとめて1つのリストで扱う
    import sys
    sys.setrecursionlimit(10**6)

    vertex_maxsize = 10**5
    target = [[] for _ in range(2 * vertex_maxsize)]
    is_visited = [False] * (2 * vertex_maxsize)
    for x, y in Positions:
        y += vertex_maxsize  # 1つのリストで扱う都合上、ずらす
        target[x].append(y)
        target[y].append(x)

    def dfs(v):
        if is_visited[v]:
            return
        is_visited[v] = True
        count[v // vertex_maxsize] += 1  # vがx軸とy軸のどっちを指しているか
        for u in target[v]:
            dfs(u)  # 頂点vに接続されている頂点へ向かう

    ans = 0
    for i in range(2 * vertex_maxsize):
        if is_visited[i]:
            continue
        count = [0] * 2
        dfs(i)  # 頂点iにつながっている頂点を調べる
        # x座標とy座標のそれぞれについて、ペアにすると矩形が完成する
        # 座標がいくつあるか。その積が解となる
        ans += count[0] * count[1]
    return ans - N  # 最初に与えられた座標の分、引く

N = int(input())
Positions = [[int(i) for i in input().split()] for j in range(N)]
print(f_must_be_rectangular(N, Positions))