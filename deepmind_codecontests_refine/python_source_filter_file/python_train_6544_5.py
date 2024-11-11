class BIT_index:
    def __init__(self, n):
        self.BIT_prev = [n] * (n + 1)
        self.BIT_next = [n] * (n + 1)
        self.n = n

    def __addElement(self, BIT, idx):
        value = idx
        idx += 1
        while idx > 0:
            BIT[idx] = min(BIT[idx], value)
            idx -= idx & -idx

    def addElement(self, idx):
        self.__addElement(self.BIT_prev, self.n - 1 - idx)
        self.__addElement(self.BIT_next, idx)

    def __getIndex(self, BIT, idx):
        idx += 1
        ans = self.n
        while idx <= self.n:
            ans = min(ans, BIT[idx])
            idx += idx & -idx
        return ans

    def getIndexPrev(self, idx):
        return self.__getIndex(self.BIT_prev, self.n - 1 - idx)

    def getIndexNext(self, idx):
        return self.__getIndex(self.BIT_next, idx)


N = int(input())
As = list(map(int, input().split()))

Bs = [i for A, i in sorted([(As[i], i) for i in range(N)])]

BIT = BIT_index(N)
ans = 0
for i, B in enumerate(Bs):
    iN = BIT.getIndexNext(B)
    iP = BIT.getIndexPrev(B)
    BIT.addElement(B)
    ans += (i + 1) * (iN - B) * (B - (N - 1 - iP))

print(ans)

