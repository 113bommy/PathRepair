import sys
input = sys.stdin.readline
class segtree:
    def __init__(self, Size, op, e, A = []):
        self.op = op
        for i in range(Size):
            if Size <= 1 << i:
                self.LeavesSize = 1 << i
                break
        self.e = e
        self.Tree = [e] *(self.LeavesSize * 2)
        for i in range(len(A)):
            self.Tree[i + self.LeavesSize - 1] = A[i]
        self.make()
    
    def make(self, i = 0):
        if i < self.LeavesSize - 1: self.Tree[i] = self.op(self.make(i * 2 + 1), self.make(i * 2 + 2))
        return self.Tree[i]
    
    def __getitem__(self, key):
        return self.Tree[key + self.LeavesSize - 1]
    
    def push(self, Index, Value):
        Index += self.LeavesSize - 1
        self.Tree[Index] = Value
        while Index != 0:
            Index = (Index - 1) // 2
            self.Tree[Index] = self.op(self.Tree[Index * 2 + 1], self.Tree[Index * 2 + 2])
    
    def get(self, A, B, Index = 0, L = 0, R = -1):
        if Index == 0: R = self.LeavesSize
        if B <= L or R <= A: return self.e
        if A <= L and R <= B: return self.Tree[Index]
        return self.op(self.get(A, B, Index * 2 + 1, L, (L + R) // 2), self.get(A, B, Index * 2 + 2, (L + R) // 2, R))
    
    def add(self, Index, Value):
        Value += self.Tree[Index + self.LeavesSize - 1]
        self.push(Index, Value)
    
    def output(self):
        p1 = 0
        p2 = 1
        print(*self.Tree[p1: p1 + p2])
        while p2 != self.LeavesSize:
            p1 += p2
            p2 *= 2
            print(*self.Tree[p1: p1 + p2])

N, Q = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = [0] + [A[i] - B[i] for i in range(N)]
for i in range(N): C[i + 1] += C[i]
print(C)
TreeMax = segtree(N, max, -10 ** 18, C)
TreeMin = segtree(N, min, 10 ** 18, C)
for _ in range(Q):
    L, R = map(int, input().split())
    L -= 1
    if C[R] - C[L] != 0 or TreeMax.get(L, R) - C[L] > 0: print(-1)
    else: print(C[L] - TreeMin.get(L, R))