import sys
from sys import stdin

mod = 10**9+7
class SegTree:

    def __init__(self,N,first):
        self.NO = 2**(N-1).bit_length()
        self.First = first
        self.data = [first] * (2*self.NO)

    def calc(self,l,r):
        return (l+r) % mod

    def update(self,ind,x):
        ind += self.NO - 1
        self.data[ind] = x
        while ind >= 0:
            ind = (ind - 1)//2
            self.data[ind] = self.calc(self.data[2*ind+1],self.data[2*ind+2])

    def query(self,l,r):
        L = l + self.NO
        R = r + self.NO
        s = self.First
        while L < R:
            if R & 1:
                R -= 1
                s = self.calc(s , self.data[R-1])
            if L & 1:
                s = self.calc(s , self.data[L-1])
                L += 1
            L >>= 1
            R >>= 1
        return s
    
    def get(self , ind):
        ind += self.NO - 1
        return self.data[ind]


tt = int(stdin.readline())

for loop in range(tt):
    
    n = int(stdin.readline())
    b = [0] + list(map(int,stdin.readline().split()))

    c = [0]
    for i in range(1,n+1):
        c.append(c[-1] + b[i])

    ctoi = {}
    tlis = []
    for i in range(len(c)):
        if c[i] not in ctoi:
            ctoi[c[i]] = 0
            tlis.append(c[i])
    tlis.sort()
    for i in range(len(tlis)):
        ctoi[tlis[i]] = i

    ST = SegTree(len(tlis),0)
    ST.update(0,1)

    for i in range(1,n+1):

        ind = ctoi[c[i-1]]
        ST.update(ind , ST.query(0,len(tlis)))

    print (ST.query(0,len(tlis)))