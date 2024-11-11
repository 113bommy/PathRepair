class Unionfind:

    __slots__ = ['parents','sizes']

    def __init__(self, n):
        self.parents = list(range(n))
        self.sizes = [1]*n

    def root(self, x):
        if self.parents[x] == x:
            return x
        else:
            root_x = self.root(self.parents[x])
            self.parents[x] = root_x
            return root_x

    def unite(self, x, y):
        x = self.root(x); y = self.root(y)
        if x == y:
            return
        if self.sizes[x] < self.sizes[y]:
            x, y = y, x
        self.sizes[x] += self.sizes[y]
        self.parents[y] = x

    def same(self, x, y):
        return self.root(x) == self.root(y)

    # 集合自体の数 ({1,2}, {3}, {4} : kind -> 3)
    def kind(self):
        for v in range(N):
            self.root(v)
        return len(list(set(self.parents)))

    # xが属する集合の要素の数　({1,2,3} : size(2) -> 3)
    def size(self, x):
        self.sizes[x] = self.sizes[self.root(x)]
        return self.sizes[x]

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
sA = sorted(enumerate(A), key=lambda x : x[1])
sB = sorted(enumerate(B), key=lambda x : x[1])

# 必要条件
if not all(a <= b for (i, a), (j, b) in zip(sA, sB)):
    print("No")
    exit()

uf = Unionfind(N)
# i -> j　に移動する
for (i, a), (j, b) in zip(sA, sB):
    uf.unite(i, j)

# サイクル数が２つ以上なら高々N-2回で理想の列が作れる
if uf.kind() > 1:
    print("Yes")
    exit()

# 以下サイクル数が１つだがN-2回以下で条件を満たすような例を弾く
# sB[i] < sA[i+1]のようなiが存在すれば sA[i] と sA[i+1]をスワップする(目標とする列)
# サイクルが２つに分かれるので条件を満たす
if any(sB[i][1] <= sA[i+1][1] for i in range(N-1)):
    print("Yes")
    exit()

#　任意のiについてsB[i] < sA[i+1]なら sB[i] と sA[i]を対応させるしかない
# AとBをそれぞれソートした列が目標の列となってこれはN-1回かかるので不適
print("No")