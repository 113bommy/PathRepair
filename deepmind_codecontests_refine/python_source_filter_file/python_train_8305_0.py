class MinSegmentTree():
    def __init__(self, n):
        self.n = n
        self.INF = n - 1
        self.size = 1
        while self.size < n:
            self.size *= 2
        self.node = [self.INF] * (2*self.size - 1)

    def update(self, i, val):
        i += (self.size - 1)
        self.node[i] = val
        while i > 0:
            i = (i - 1) // 2
            self.node[i] = min(self.node[2*i + 1], self.node[2*i + 2])

    def get_min(self, begin, end):
        begin += (self.size - 1)
        end += (self.size - 1)
        s = self.INF
        while begin < end:
            if (end - 1) & 1:
                end -= 1
                s = min(s, self.node[end])
            if (begin - 1) & 1:
                s = min(s, self.node[begin])
                begin += 1
            begin = (begin - 1) // 2
            end = (end - 1) // 2
        return s

class MaxSegmentTree():
    def __init__(self, n):
        self.n = n
        self.INF = 0
        self.size = 1
        while self.size < n:
            self.size *= 2
        self.node = [self.INF] * (2*self.size - 1)

    def update(self, i, val):
        i += (self.size - 1)
        self.node[i] = val
        while i > 0:
            i = (i - 1) // 2
            self.node[i] = max(self.node[2*i + 1], self.node[2*i + 2])

    def get_max(self, begin, end):
        begin += (self.size - 1)
        end += (self.size - 1)
        s = self.INF
        while begin < end:
            if (end - 1) & 1:
                end -= 1
                s = max(s, self.node[end])
            if (begin - 1) & 1:
                s = max(s, self.node[begin])
                begin += 1
            begin = (begin - 1) // 2
            end = (end - 1) // 2
        return s


n = int(input())
a = list(map(int, input().split()))

ind = {}
for i in range(n):
    ind[a[i]] = i
smax = MaxSegmentTree(n+2)
smin = MinSegmentTree(n+2)

ans = 0
for i in range(n):
    pos = ind[n-i] + 1
    l2 = smax.get_max(0, pos)
    l1 = smax.get_max(0, l2)
    r1 = smin.get_min(pos+1, n+3)
    r2 = smin.get_min(r1+1, n+3)
    smin.update(pos, pos)
    smax.update(pos, pos)
    ans += ((l2 - l1) * (r1 - pos) + (r2 - r1) * (pos - l2)) * (n-i)
print(ans)
