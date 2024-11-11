import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,Q,A,B,*X = map(int,read().split())

class MinSegTree():
    def __init__(self,N):
        self.Nelem = N
        self.size = 1<<(N.bit_length()) # 葉の要素数
        
    def build(self,raw_data):
        # raw_data は 0-indexed
        INF = 10**18
        self.data = [INF] * (2*self.size)
        for i,x in enumerate(raw_data):
            self.data[self.size+i] = x
        for i in range(self.size-1,0,-1):
            x = self.data[i+i]; y = self.data[i+i+1]
            self.data[i] = x if x<y else y
    
    def update(self,i,x):
        i += self.size
        self.data[i] = x
        i >>= 1
        while i:
            x = self.data[i+i]; y = self.data[i+i+1]
            self.data[i] = x if x<y else y
            i >>= 1
    
    def get_value(self,L,R):
        # [L,R] に対する値を返す
        L += self.size
        R += self.size + 1
        # [L,R) に変更
        x = 10**18
        while L < R:
            if L&1:
                y = self.data[L]
                if x > y: x = y
                L += 1
                
            if R&1:
                R -= 1
                y = self.data[R]
                if x > y: x = y
            L >>= 1; R >>= 1
        return x

INF = 10**18
dpL = MinSegTree(N+10); dpL.build([INF] * (N+10))
dpR = MinSegTree(N+10); dpR.build([INF] * (N+10))
dpL.update(A,0-A)
dpR.update(A,0+A)

prev_x = B
add = 0
for x in X:
    from_left = dpL.get_value(0,x) + x
    from_right = dpR.get_value(x,N+10) - x
    dist = x-prev_x if x>prev_x else prev_x-x
    y = from_left if from_left < from_right else from_right
    y -= dist
    dpL.update(prev_x,y-prev_x)
    dpR.update(prev_x,y+prev_x)
    add += dist
    prev_x = x

dp = [(x+y)//2 for x,y in zip(dpL.data[dpL.size:],dpR.data[dpR.size:])]
answer = min(dp) + add
print(answer)
