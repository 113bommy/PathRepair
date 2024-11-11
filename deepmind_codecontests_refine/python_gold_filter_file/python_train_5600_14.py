import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import itertools

N = int(readline())
A = list(map(int,readline().split()))
B = list(map(int,readline().split()))

class BinaryIndexedTree():
    def __init__(self, seq):
        self.size = len(seq)
        self.depth = self.size.bit_length()
        self.build(seq)
        
    def build(self,seq):
        data = seq
        size = self.size
        for i,x in enumerate(data):
            j = i+(i&(-i))
            if j < size:
                data[j] += data[i]
        self.data = data
        
    def __repr__(self):
        return self.data.__repr__()
        
    def get_sum(self,i):
        data = self.data
        s = 0
        while i:
            s += data[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        data = self.data
        size = self.size
        while i < size:
            data[i] += x
            i += i & -i
    
    def find_kth_element(self,k):
        data = self.data; size = self.size
        x,sx = 0,0
        dx = 1 << (self.depth)
        for i in range(self.depth - 1, -1, -1):
            dx = (1 << i)
            if x + dx >= size:
                continue
            y = x + dx
            sy = sx + data[y]
            if sy < k:
                x,sx = y,sy
        return x + 1

def Inversion(seq):
    # seqは、1,2,...,Nの順列
    N = len(seq)
    bit = BinaryIndexedTree([0] * (N+1))
    inv = N*(N-1)//2
    for x in seq:
        inv -= bit.get_sum(x)
        bit.add(x,1)
    return inv

INF = 10 ** 9
answer = INF
for I in itertools.combinations(range(N),(N+1)//2):
    J = [j for j in range(N) if j not in I]
    ODD = [(B[i] if i&1 else A[i],i) for i in I]
    EV = [(A[i] if i&1 else B[i],i) for i in J]
    ODD.sort()
    EV.sort()
    ind = [0] * N
    seq = [0] * N
    for i in range(0,N,2):
        seq[i], ind[i] = ODD[i//2]
    for i in range(1,N,2):
        seq[i], ind[i] = EV[i//2]
    if not all(x<= y for x,y in zip(seq,seq[1:])):
        continue
    ind = [x+1 for x in ind]
    n = Inversion(ind)
    if answer > n:
        answer = n

if answer == INF:
    answer = -1
print(answer)
