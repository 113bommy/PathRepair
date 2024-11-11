import sys
input = sys.stdin.readline

class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0]*(n+1)
 
    def sum(self, i):
        # [0, i) の要素の総和を返す
        s = 0
        while i>0:
            s += self.tree[i]
            i -= i & -i
        return s
    # 0 index を 1 index に変更  転倒数を求めるなら1を足していく
    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


n,q = map(int,input().split())
c = list(map(int,input().split()))
Q = []
for i in range(q):
    l,r = map(int,input().split())
    Q.append([l,r,i])

Q.sort(key=lambda x: x[1])

bit = BIT(n)
ind = [-1]*(n+1)

ans = [0]*q
now = 0
for l,r,num in Q:
    while now < r:
        x = c[now]
        if ind[x] == -1:
            ind[x] = now
            bit.add(now,1)
        else:
            bit.add(ind[x],-1)
            ind[x] = now
            bit.add(now,1)
        now += 1
    ans[num] = bit.sum(r)-bit.sum(l-1)
for i in ans:
    print(i)

