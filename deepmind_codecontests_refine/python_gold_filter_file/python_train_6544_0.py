import sys
sys.setrecursionlimit(10 ** 7)
 
input = sys.stdin.buffer.readline

class SegTree():
    # 1-indexed
    def __init__(self, N, function, basement):
        self.n = N
        self.K = (self.n-1).bit_length()
        self.f = function
        self.b = basement
        self.seg = [basement]*(2**(self.K+1)+1)

    def update(self, k, value):
        X = 2**self.K
        k += X
        self.seg[k] = value
        while k:
            k = k >> 1
            self.seg[k] = self.f(self.seg[k << 1], self.seg[(k << 1) | 1])

    def query(self, L, R):
        num = 2**self.K
        L += num
        R += num
        vL = self.b
        vR = self.b
        while L < R:
            if L & 1:
                vL = self.f(vL, self.seg[L])
                L += 1
            if R & 1:
                R -= 1
                vR = self.f(self.seg[R], vR)
            L >>= 1
            R >>= 1
        return self.f(vL, vR)

    def find_max_index(self, L, R, X):
        # [L,R)でX以下の物で最大indexを取得
        return self.fMi(L, R, X, 1, 0, 2**self.K)

    def find_min_index(self, L, R, X):
        # [L,R) でX以下の物で最小のindexを取得する
        return self.fmi(L, R, X, 1, 0, 2**self.K)

    def fMi(self, a, b, x, k, l, r):
        if self.seg[k] > x or r <= a or b <= l:
            return -1
        else:
            if k >= 2**self.K:
                return k-2**self.K
            else:
                vr = self.fMi(a, b, x, (k << 1) | 1, (l + r) // 2, r)
                if vr != -1:
                    return vr
                return self.fMi(a, b, x, k << 1, l, (l + r) // 2)

    def fmi(self, a, b, x, k, l, r):
        if self.seg[k] > x or r <= a or b <= l:
            return -1
        else:
            if k >= 2**self.K:
                return k-2**self.K
            else:
                vl = self.fmi(a, b, x, k << 1, l, (l+r)//2)
                if vl != -1:
                    return vl
                return self.fmi(a, b, x, k << 1 | 1, (l+r)//2, r)

def main():
    N = int(input())
    A = list(map(int, input().split()))
    seg = SegTree(N, min, N+1)
    B = [0]*N
    for i, v in enumerate(A):
        B[i] = (i, A[i])
    B.sort(key=lambda x: x[1])
    ans = 0
    for index, v in B:
        seg.update(index, 1)
        left = seg.find_max_index(0, index, 1)
        right = seg.find_min_index(index+1, N, 1)
        if right == -1:
            right = N
        ans += v*(index-left)*(right-index)
    print(ans)
if __name__=="__main__":
    main()
