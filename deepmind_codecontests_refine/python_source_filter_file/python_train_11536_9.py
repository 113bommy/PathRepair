def main():
    n, m = map(int, input().split())
    if m % 2:
        print(-1)
        return
    ab = [list(map(int, input().split())) for _ in [0]*m]
    g = [set() for _ in [0]*n]
    [g[a-1].add(b-1) for a, b in ab]
    [g[b-1].add(a-1) for a, b in ab]
    ab = [(a-1, b-1)for a, b in ab]

    def Kruskal(n, abc, weight=False):
        class unionfind():
            # size:要素数,tree：unionfind木
            def __init__(self, size):  # self,要素数
                self.size = size
                self.tree_root = list(range(self.size))
                self.tree_depth = [1]*self.size

            # rootを探す
            def root(self, index):
                temp_list = []
                temp = self.tree_root[index]
                while index != temp:
                    temp_list.append(index)
                    index = temp
                    temp = self.tree_root[index]
                for i in temp_list:
                    self.tree_root[i] = index
                return index

            # 結合
            def unite(self, index1, index2):
                r1 = self.root(index1)
                r2 = self.root(index2)
                if r1 != r2:
                    d1, d2 = self.tree_depth[r1], self.tree_depth[r2]
                    if d1 <= d2:
                        self.tree_root[r1] = r2
                        self.tree_depth[r2] = max(d1+1, d2)
                    else:
                        self.tree_root[r2] = r1
                        self.tree_depth[r1] = max(d2+1, d1)

            # 同じか判定
            def same(self, index1, index2):
                r1 = self.root(index1)
                r2 = self.root(index2)
                return r1 == r2

            # 連結成分の個数
            def component(self):
                return len({self.root(i) for i in range(self.size)})
        uf = unionfind(n)
        ret = []
        if weight:
            abc.sort(key=lambda x: x[2])
        for a, b, *c in abc:
            if not uf.same(a, b):
                ret.append([a, b])
                uf.unite(a, b)
        return ret

    t = Kruskal(n, ab)
    g2 = [set() for _ in [0]*n]
    [g2[a].add(b) for a, b in t]
    [g2[b].add(a) for a, b in t]
    root = 0  # 根
    d = [-1]*n  # 根からの距離
    d[root] = 0
    q = [root]
    cnt = 0
    while q:  # BFS
        cnt += 1
        qq = []
        while q:
            i = q.pop()
            for j in g[i]:
                if d[j] == -1:
                    d[j] = cnt
                    qq.append(j)
        q = qq

    d2 = sorted([(i, j) for i, j in enumerate(d)], key=lambda x: -x[1])
    now = [0]*n
    ans = []
    for i, j in d2:
        remove_list = []
        for k in g[i]:
            if k not in g2[i]:
                now[i] += 1
                ans.append((i+1, k+1))
                remove_list += [(i, k), (k, i)]
        for k, l in remove_list:
            g[k].remove(l)
    for i, j in d2[:-1]:
        k = g[i].pop()
        g[k].remove(i)
        if now[i] % 2:
            now[i] += 1
            ans.append((i+1, k+1))
        else:
            now[k] -= 1
            ans.append((k+1, i+1))
    for i in ans:
        print(*i)


main()
