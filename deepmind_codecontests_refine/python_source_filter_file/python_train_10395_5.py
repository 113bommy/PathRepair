"""
.o...o..o.
....o.....
....oo.oo.
..oooo..o.
....oo....
..o..o....
o..o....So
o....T....
....o.....
........oo

グラフを作る
⇛ SからTにたどり着く個数を全探索
⇛ たどり着く直前の座標を保持
⇛ 直前のバリエーション
解説AC
⇛ 行内、列内は自由に動ける
⇛ 行/列のどこかにいる状態でもたせる
⇛ 点の上は行⇔列の切り替えが出来るので、cap==1とする
⇛ 結局MaxCutをしているのと一緒！！
"""

from collections import deque
from collections import defaultdict
import sys
sys.setrecursionlimit(100000)
class Dinic:
    def __init__(self):
        # self.N = N
        self.G = defaultdict(list)
    
    def add_edge(self, fr, to, cap):
        """
        :param fr: 始点
        :param to: 終点
        :param cap: 容量
        """
        # forwardの最後には、キャパのうちどれだけ使ったかが入る
        forward = [to, cap, None]
        backward = [fr, 0, forward]
        forward[-1] = backward
        self.G[fr].append(forward)
        self.G[to].append(backward)

    def add_multi_edge(self, v1, v2, cap1, cap2):
        """
        :param v1: 始点
        :param v2: 終点
        :param cap1: 容量1
        :param cap2: 容量2
        """
        edge1 = [v2, cap1, None]
        edge2 = [v1, cap2, edge1]
        edge1[-1] = edge2
        self.G[v1].append(edge1)
        self.G[v2].append(edge2)

    def bfs(self, s, t):
        """
        :param s: bfsの始点(source)
        :param t: bfsの終点(sink)
        :return: tに到達したかどうか。(sourceからの距離を保存しながら)
        """
        self.level = level = defaultdict(int)
        q = deque([s])
        level[s] = 1
        G = self.G
        while len(q) > 0:
            v = q.popleft()
            lv = level[v] + 1
            nexts = G[v]
            for w, cap, _ in nexts:
                if cap > 0 and level[w] == 0:
                    level[w] = lv
                    q.append(w)
        is_reach = (level[t] > 0)
        return is_reach

    def dfs(self, v, t, f):
        """
        :param v: 点v
        :param t: 終点(sink)
        :param f: v時点でのフロー
        :return: 終点到達時のフローを返す
        """   
        if v == t:
            return f
        level = self.level
        nexts = self.G[v]
        for edge in nexts:
            w, cap, rev = edge
            # まだキャパがあるならば
            if cap > 0 and level[v] < level[w]:
                # キャパが余ってるなら全部流すし
                # カツカツならキャパのmaxまで流す
                d = self.dfs(w, t, min(f, cap))
                # 帰りがけに、更新
                if d > 0:
                    # 順方向のキャパをd下げる
                    # 逆方向のキャパをd増やす
                    edge[1] -= d
                    rev[1] += d
                    return d
        # 次の道が見つからなければ終了
        return 0
    
    def flow(self, s, t):
        """
        :param s: 始点
        :param t: 終点
        :return : 最大フロー
        """
        flow = 0
        INF = 10**10
        G = self.G
        # ルートが存在する限り、続ける
        while self.bfs(s, t):
            f = INF
            while f > 0:
                f = self.dfs(s, t, INF)
                flow += f
        return flow



ans = set()
H, W = map(int, input().split())
fields = []
for i in range(H):
    inp = list(input())
    fields.append(inp)
dinic = Dinic()
start = -1
end = -2
INF = 10**10
for i in range(H):
    for j in range(W):
        if fields[i][j] == "T":
            dinic.add_edge(i,end,INF)
            dinic.add_edge(j+H,end,INF)
        if fields[i][j] == "S":
            dinic.add_edge(start,i,INF)
            dinic.add_edge(start,j+H,INF)
        if fields[i][j] == "o":
            dinic.add_edge(i,j+H,1)
            dinic.add_edge(j+H,i,1)

ans = dinic.flow(start,end)
if ans == INF:print(-1)
else:print(ans)
