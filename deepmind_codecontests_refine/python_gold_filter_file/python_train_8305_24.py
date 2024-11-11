INF = 10**9

class RmQ:
    def __init__(self, a):
        self.n = len(a)
        self.size = 2**(self.n - 1).bit_length()
        self.data_min = [INF] * (2*self.size-1)
        self.initialize(a)

    # Initialize data
    def initialize(self, a):
        for i in range(self.n):
            self.data_min[self.size + i - 1] = a[i]
        for i in range(self.size-2, -1, -1):
            self.data_min[i] = min(self.data_min[i*2 + 1], self.data_min[i*2 + 2])

    # Update ak as x
    def update(self, k, x):
        k += self.size - 1
        self.data_min[k] = x
        while k > 0:
            k = (k - 1) // 2
            self.data_min[k] = min(self.data_min[2*k+1], self.data_min[2*k+2])

    # Min value in [l, r)
    def query(self, l, r):
        L = l + self.size; R = r + self.size
        s = INF
        while L < R:
            if R & 1:
                R -= 1
                s = min(s, self.data_min[R-1])
            if L & 1:
                s = min(s, self.data_min[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s

class RMQ:
    def __init__(self, a):
        self.n = len(a)
        self.size = 2**(self.n - 1).bit_length()
        self.data_max = [-INF] * (2*self.size-1)
        self.initialize(a)

    # Initialize data_min
    def initialize(self, a):
        for i in range(self.n):
            self.data_max[self.size + i - 1] = a[i]
        for i in range(self.size-2, -1, -1):
            self.data_max[i] = max(self.data_max[i*2 + 1], self.data_max[i*2 + 2])

    # Update ak as x
    def update(self, k, x):
        k += self.size - 1
        self.data_max[k] = x
        while k > 0:
            k = (k - 1) // 2
            self.data_max[k] = max(self.data_max[2*k+1], self.data_max[2*k+2])

    # Max value in [l, r)
    def query(self, l, r):
        L = l + self.size; R = r + self.size
        s = -INF 
        while L < R:
            if R & 1:
                R -= 1
                s = max(s, self.data_max[R-1])
            if L & 1:
                s = max(s, self.data_max[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s

n = int(input())
a = [int(item) for item in input().split()]
indexes = [0] * n
for i, item in enumerate(a):
    indexes[item - 1] = i
indexes.reverse()

a_min = [-1] * 2 + [INF] * n + [n] * 2
a_max = [-1] * 2 + [-INF] * n + [n] * 2
rMq = RMQ(a_max)
rmq = RmQ(a_min)
ans = 0
for i, idx in enumerate(indexes):
    num = n - i
    L1 = rMq.query(0, idx+2)
    L2 = rMq.query(0, L1+2)
    R1 = rmq.query(idx+2, n+4)
    R2 = rmq.query(R1+3, n+4)
    ans += (L1 - L2) * (R1 - idx) * num 
    ans += (idx - L1) * (R2 - R1) * num 
    rMq.update(idx+2, idx)
    rmq.update(idx+2, idx)
print(ans)