class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0]*(n+1)

    def __iter__(self):
        psum = 0
        for i in range(self.size):
            csum = self.sum(i+1)
            yield csum - psum
            psum = csum
        raise StopIteration()

    def __str__(self):  # O(nlogn)
        return str(list(self))

    def sum(self, i):
        # [0, i) の要素の総和を返す
        if not (0 <= i <= self.size): raise ValueError("error!")
        s = 0
        while i>0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        if not (0 <= i < self.size): raise ValueError("error!")
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def __getitem__(self, key):
        if not (0 <= key < self.size): raise IndexError("error!")
        return self.sum(key+1) - self.sum(key)

    def __setitem__(self, key, value):
        # 足し算と引き算にはaddを使うべき
        if not (0 <= key < self.size): raise IndexError("error!")
        self.add(key, value - self[key])

from operator import itemgetter
import sys
input = sys.stdin.readline
mod = 998244353
N = int(input())
XY = [list(map(int, input().split())) for _ in range(N)]
XY.sort(key=itemgetter(1))
for i in range(N):
    XY[i][1] = i
XY.sort(key=itemgetter(0))
bitL = Bit(N)
bitR = Bit(N)
L = []  # 左下
R = [0]*N  # 右下
for _, y in XY:
    L.append(bitL.sum(y))
    bitL.add(y, 1)
for i, (_, y) in zip(range(N-1,-1,-1), XY[::-1]):
    R[i] = bitR.sum(y)
    bitR.add(y, 1)
ans = N * pow(2, N-1, mod) % mod
#print(ans)
for i, (ld, rd) in enumerate(zip(L, R)):
    lu = i - ld
    ru = N - 1 - i - rd
    #print(lu, ld, ru, rd)
    p_lu, p_ld, p_ru, p_rd = pow(2,lu,mod), pow(2,ld,mod), pow(2,ru,mod), pow(2,rd,mod)
    d = p_ru*p_ld*(p_lu-1)*(p_rd-1)\
           + p_lu*p_rd*(p_ru-1)*(p_ld-1)\
           - (p_lu-1)*(p_rd-1)*(p_ru-1)*(p_ld-1)
    #print(d)
    ans = (ans + d) % mod
#print(L)
#print(R)

print(ans)
