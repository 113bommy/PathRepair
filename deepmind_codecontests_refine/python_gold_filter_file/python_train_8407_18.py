class SegmentTree:
    def __init__(self, a):
        self.padding = 0
        self.n = len(a)
        self.N = 2 ** (self.n-1).bit_length()
        self.seg_data = [self.padding]*(self.N-1) + a + [self.padding]*(self.N-self.n)
        for i in range(2*self.N-2, 0, -2):
            self.seg_data[(i-1)//2] = self.seg_data[i] + self.seg_data[i-1]
    
    def __len__(self):
        return self.n
    
    def update(self, i, x):
        idx = self.N - 1 + i
        self.seg_data[idx] += x
        while idx:
            idx = (idx-1) // 2
            self.seg_data[idx] = self.seg_data[2*idx+1] + self.seg_data[2*idx+2]
    
    def query(self, i, j):
        # [i, j)
        if i == j:
            return self.seg_data[self.N - 1 + i]
        else:
            idx1 = self.N - 1 + i
            idx2 = self.N - 2 + j # 閉区間にする
            result = self.padding
            while idx1 < idx2 + 1:
                if idx1&1 == 0: # idx1が偶数
                    result = result + self.seg_data[idx1]
                if idx2&1 == 1: # idx2が奇数
                    result = result + self.seg_data[idx2]
                    idx2 -= 1
                idx1 //= 2
                idx2 = (idx2 - 1)//2
            return result
    
    @property
    def data(self):
        return self.seg_data[self.N-1:self.N-1+self.n]

N, Q = map(int, input().split())
A = list(map(int, input().split()))
st = SegmentTree(A)
ans = []
for _ in range(Q):
    t, i, j = map(int, input().split())
    if t:
        ans.append(st.query(i, j))
    else:
        st.update(i, j)

print(*ans, sep='\n')