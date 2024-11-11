class UnionFind(object):
    """
    Union-Find構造
    ノードのグループ併合や、所属グループ判定を高速に処理する
    """

    def __init__(self, group_id, x_zahyou, y_zahyou,parent=None, value=None):
        self.group_id_ = group_id
        self.x_zahyou = x_zahyou
        self.y_zahyou = y_zahyou
        self.parent_ = parent
        self.value = value
        self.rank_ = 1

    def __str__(self):
        template = "UnionFindNode(group_id: {}, \n\tparent: {}, value: {}, size: {})"
        return template.format(self.group_id_, self.parent_, self.value, self.rank_)

    def is_root(self):
        return not self.parent_

    def root(self):
        parent = self
        while not parent.is_root():
            parent = parent.parent_
            self.parent_ = parent
        return parent

    def find(self):
        root = self.root()
        return root.group_id_

    def rank(self):
        root = self.root()
        return root.rank_

    def unite(self, unite_node):
        root = self.root()
        unite_root = unite_node.root()

        if root.group_id_ != unite_root.group_id_:
            if root.rank() > unite_root.rank():
                unite_root.parent_ = root
                root.rank_ = max(root.rank_, unite_root.rank_ + 1)
                root.x_zahyou += unite_root.x_zahyou
                root.y_zahyou += unite_root.y_zahyou
            else:
                root.parent_ = unite_root
                unite_root.rank_ = max(root.rank_ + 1, unite_root.rank_)
                unite_root.x_zahyou+= root.x_zahyou 
                unite_root.y_zahyou+= root.y_zahyou
                
N = int(input())
X = []
Y = []
node_list = []
for i in range(N):
  x, y = map(int,input().split())
  X += [[i,x]]
  Y += [[i,y]]
  node_list += [UnionFind(i,[x],[y])]
X.sort(key=lambda x: x[1])
Y.sort(key=lambda x: x[1])
for i in range(N-1):
  if X[i][1] == X[i+1][1] :
    node_list[X[i][0]].unite(node_list[X[i+1][0]])
  if Y[i][1] == Y[i+1][1] :
    node_list[Y[i][0]].unite(node_list[Y[i+1][0]])
    
chouten = 0
for i in range(N):
  if node_list[i].is_root():
    chouten += len(set(node_list[i].x_zahyou)) * len(set(node_list[i].y_zahyou))
    
print(chouten - N)