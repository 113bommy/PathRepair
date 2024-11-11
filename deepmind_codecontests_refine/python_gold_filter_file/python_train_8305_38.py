# instead of AVLTree
class BITbisect():
    def __init__(self, max):
        self.max = max
        self.data = [0]*(self.max+1)
    
    # 0からiまでの区間和
    # 立っているビットを下から処理
    def query_sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s

    # i番目の要素にxを足す
    # 覆ってる区間すべてに足す
    def add(self, i, x):
        while i <= self.max:
            self.data[i] += x
            i += i & -i

    def insert(self, x):
        self.add(x, 1)

    def delete(self, x):
        self.add(x, -1)

    def count(self, x):
        return self.query_sum(x) - self.query_sum(x-1)
    
    def length(self):
        return self.query_sum(self.max)
    
    # 下からc番目(0-indexed)の数
    # O(log(N))
    def search(self, c):
        c += 1
        s = 0
        ind = 0
        l = self.max.bit_length()
        for i in reversed(range(l)):
            if ind + (1<<i) <= self.max:
                if s + self.data[ind+(1<<i)] < c:
                    s += self.data[ind+(1<<i)]
                    ind += (1<<i)
        if ind == self.max:
            return False
        return ind + 1
    
    def bisect_right(self, x):
        return self.query_sum(x)

    def bisect_left(self, x):
        if x == 1:
            return 0
        return self.query_sum(x-1)

    # listみたいに表示
    def display(self):
        print('inside BIT:', end=' ')
        for x in range(1, self.max+1):
            if self.count(x):
                c = self.count(x)
                for _ in range(c):
                    print(x, end=' ')
        print()

import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
bit = BITbisect(N)

co_to_ind = [0]*(N+1)
for i in range(N):
    co_to_ind[A[i]] = i+1
    bit.insert(i+1)

ans = 0
for n in range(1, N+1):
    ind = co_to_ind[n]
    seq = bit.bisect_left(ind)
    L = bit.length()
    if seq >= 2:
        l1 = bit.search(seq-1)
        l0 = bit.search(seq-2)
    elif seq == 1:
        l1 = bit.search(seq-1)
        l0 = 0
    else:
        l1 = 0
        l0 = 0
    if L-1 - seq >= 2:
        r1 = bit.search(seq+1)
        r0 = bit.search(seq+2)
    elif L-1 - seq == 1:
        r1 = bit.search(seq+1)
        r0 = N+1
    else:
        r1 = N+1
        r0 = N+1
    #print(n,l0,l1, r1, r0, ((ind-l1)*(r0-r1) + (l1-l0)*(r0-ind)))
    ans += ((ind-l1)*(r0-r1) + (l1-l0)*(r1-ind)) * n
    bit.delete(ind)

print(ans)