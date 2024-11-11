class SegmentTree:
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        self.range = [(-1,n)] * 2 * self.num
        # 配列の値を葉にセット
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
            self.range[self.num + i] = (i,i)
        # 構築していく
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])
            self.range[i] = (self.range[2 * i][0],self.range[2 * i + 1][1])

    def update(self, k, x):
        k += self.num
        self.tree[k] = x
        while k > 1:
            self.tree[k >> 1] = self.segfunc(self.tree[k], self.tree[k ^ 1])
            k >>= 1

    def query(self, l, r):
        res = self.ide_ele

        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res

    def bisect_l(self,l,r,x):
        l += self.num
        r += self.num
        Lmin = -1
        Rmin = -1
        while l<r:
            if l & 1:
                if self.tree[l] <= x and Lmin==-1:
                    Lmin = l
                l += 1
            if r & 1:
                if self.tree[r-1] <=x:
                    Rmin = r-1
            l >>= 1
            r >>= 1

        if Lmin != -1:
            pos = Lmin
            while pos<self.num:
                if self.tree[2 * pos] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        elif Rmin != -1:
            pos = Rmin
            while pos<self.num:
                if self.tree[2 * pos] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        else:
            return -1

n = int(input())
p = list(map(int,input().split()))

pos = [[] for i in range(n+2)]
for i in range(n):
    pos[p[i]].append(i)

query = [[] for i in range(n)]

for i in range(1,n+2):
    for j in range(len(pos[i])-1):
        L = pos[i][j] + 1
        R = pos[i][j+1] - 1
        if L<=R:
            query[R].append((L,i))
    if pos[i]:
        if pos[i][0]!=0:
            query[pos[i][0]-1].append((0,i))
        if pos[i][-1]!=n-1:
            query[n-1].append((pos[i][-1]+1,i))
    else:
        query[n-1].append((0,i))

#print(query)

flag = [False for i in range(n+3)]

init = [-1]*(n+2)
init[0] = n
lastappeared = SegmentTree(init,min,-1)
for i in range(n):
    lastappeared.update(p[i],i)
    for l,val in query[i]:
        check = lastappeared.bisect_l(0,n+2,l-1)
        #print(l,i,val,check)
        #pp = [lastappeared.tree[j+lastappeared.num] for j in range(n)]

        if check>=val or check==-1:
            flag[val] = True


for i in range(1,n+3):
    if not flag[i]:
        print(i)
        break