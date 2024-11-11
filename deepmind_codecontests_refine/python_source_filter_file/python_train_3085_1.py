class UnionFind():
    def __init__(self, n ,cost):
        self.table = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]
        self.cost = cost[:]
        self.cost.insert(0,0)

    def unite(self, x, y):
        # x,yの根を格納する 
        x = self.find(x)
        y = self.find(y)

        #同一グラフ内だった場合
        if x == y:
            return False

        if self.rank[x] > self.rank[y]:
            self.table[y] = x
        else:
            self.table[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1

        if self.cost[x] > self.cost[y]:
            self.cost[x] = self.cost[y]
        else:
        	self.cost[y] = self.cost[x]


    def find(self, x):
        """ xの根の値を返すメソッド """
        #xが根である時
        if self.table[x] == x:
            return x
        #xが根でない ==> 根へたどる&根へつけかえる
        self.table[x] = self.find(self.table[x])
        #根の値を返す
        return self.table[x]

    def SameGragh(self,x,y):
        """二つの値が同一グラフ内だった場合:True,違う場合:False"""
        if self.find(x) == self.find(y):
            return True
        else:
            return False

    def sumCost(self):
    	sumval = 0
    	for i in range(1,n+1):
    		if self.rank[i] == 1:
    			sumval += self.cost[i]

    	return sumval

if __name__ == "__main__":
	n,m = map(int,input().split(" "))
	cost = list(map(int,input().split(" ")))
	group = UnionFind(n+1,cost)
	used = [0] * (n+1)

	for i in range(m):
		a,b = map(int,input().split(" "))
		if not group.SameGragh(a,b):
			group.unite(a,b)

	print(group.sumCost())
