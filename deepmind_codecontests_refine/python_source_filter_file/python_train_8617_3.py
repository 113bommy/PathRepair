import sys
input = sys.stdin.readline
N = int(input())
S = input().rstrip()
Q = int(input())
qs = [input().split() for i in range(Q)]

def ctoi(c):
    return ord(c) - ord('a')

class BinaryIndexedTree:
    def __init__(self,size):
        self.N = size
        self.bit = [0]*size
    def add(self,x,w):
        while x < self.N:
            self.bit[x] += w
            x += (x & -x)
    def sum(self,x):
        ret = 0
        while x > 0:
            ret += self.bit[x]
            x -= (x & -x)
        return ret
bits = [BinaryIndexedTree(N) for _ in range(26)]

for i,c in enumerate(S):
    bits[ctoi(c)].add(i+1,1)

s = list(S)
ans = []
for a,b,c in qs:
    if a=='1':
        x = int(b)
        bits[ctoi(c)].add(x,1)
        bits[ctoi(s[x-1])].add(x,-1)
        s[x-1] = c
    else:
        tmp = 0
        for i in range(26):
            if bits[i].sum(int(c)) - bits[i].sum(int(b)-1) > 0:
                tmp += 1
        ans.append(tmp)
print(*ans, sep='\n')