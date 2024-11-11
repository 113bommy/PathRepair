INF = 10 ** 9
import sys
sys.setrecursionlimit(100000000)
dy = (-1,0,1,0)
dx = (0,1,0,-1)
from  copy import deepcopy
from bisect import bisect_left

class SegmentTree():

    def __init__(self,init_val,func,unit): #init_valは長さnの配列 O(2*n)
        n = len(init_val)
        self.unit = unit #unitは単位元
        self.size = pow(2,n - 1).bit_length() #n以上の最小の2のべき乗
        self.seg = [self.unit] * (2 * self.size) #セグメントツリー本体
        self.f = func #セグ木により異なる関数
        
        for i in range(n):
            self.seg[i + self.size - 1] = init_val[i] 
        
        for i in range(self.size - 2,-1,-1):
            self.seg[i] = self.f(self.seg[2 * i + 1],self.seg[2 * i + 2])
    
    def update(self,k,x): #k番目の要素をxに変更する O(logN)
        k += self.size - 1
        self.seg[k] = x
        while k:
            k = (k - 1)//2
            self.seg[k] = self.f(self.seg[2 * k + 1],self.seg[2 * k + 2])
    
    def query(self,p,q): #[p,q)のクエリに答える　半開区間であることに注意 O(logN)
        if q <= p:
            return self.unit

        p += self.size - 1 
        q += self.size - 2
        res = self.unit

        while q - p > 1:

            if (p&1) == 0:
                res = self.f(res,self.seg[p])

            if (q&1) == 1:
                res = self.f(res,self.seg[q])
                q -= 1

            p //= 2
            q = (q - 1)//2
        
        if p == q:
            res = self.f(res,self.seg[p])
        else:
            res = self.f(self.f(res,self.seg[p]),self.seg[q])
        
        return res


def main():
    n = int(input())
    H = list(map(int,input().split()))
    A = list(map(int,input().split()))
    
    dp = SegmentTree([0] * (n + 1),max,0)
    ans = 0
    for i in range(n):
        before_beaty = dp.query(0,H[i])
        if dp.query(H[i],H[i] + 1) < A[i] + before_beaty:
            dp.update(H[i],before_beaty + A[i])
            ans = max(ans,before_beaty + A[i])
    
    print(ans)
if __name__ == '__main__':
    main() 