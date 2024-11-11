class SegmentTree:
    def __init__(self, a, mode='min'):
        if mode == 'min':
            self.padding = float('inf')
            self.func = min
        elif mode == 'max':
            self.padding = -float('inf')
            self.func = max
        elif mode == 'sum':
            self.padding = 0
            self.func = sum
        
        n = len(a)
        self.N = 2 ** (n-1).bit_length()
        self.data = [self.padding]*(self.N-1) + a + [self.padding]*(self.N-n)
        for i in range(2*self.N-2, 0, -2):
            self.data[(i-1)//2] = self.func([self.data[i], self.data[i-1]])
    
    def update(self, i, x):
        idx = self.N - 1 + i
        self.data[idx] = x
        while idx:
            idx = (idx-1) // 2
            self.data[idx] = self.func([self.data[2*idx+1], self.data[2*idx+2]])
    
    def search(self, i, j):
        # [i, j)
        if i == j:
            return self.data[self.N - 1 + i]
        else:
            idx1 = self.N - 1 + i
            idx2 = self.N - 2 + j # 閉区間にする
            result = self.padding
            while idx1 + 1 < idx2:
                if idx1&1 == 0: # idx1が偶数
                    result = self.func([result, self.data[idx1]])
                if idx2&1 == 1: # idx2が奇数
                    result = self.func([result, self.data[idx2]])
                    idx2 -= 1
                
                idx1 //= 2
                idx2 = (idx2 - 1)//2
            
            if idx1 == idx2:
                result = self.func([result, self.data[idx1]])
            else: # idx1 + 1 == idx2
                result = self.func([result, self.data[idx1], self.data[idx2]])
            
            return result


N = int(input())
H = list(map(int, input().split()))
A = list(map(int, input().split()))

dp = [0] * (N+1)
st = SegmentTree(dp, 'max')

ans = 0
for h, a in zip(H, A):
  M = st.search(0, h)
  st.update(h, M + a)

print(st.search(0, N+1))