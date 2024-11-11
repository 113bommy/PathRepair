import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(readline())
B = list(map(int,readline().split()))
Q = int(readline())
m = map(int,read().split())
LR = sorted(zip(m,m))

class MaxSegTree():
    def __init__(self,raw_data):
        N = len(raw_data)
        self.size = 1<<(N.bit_length()) # 葉の要素数
        self.data = [0] * (2*self.size)
        self.build(raw_data)
        
    def build(self,raw_data):
        for i,x in enumerate(raw_data):
            self.data[self.size+i] = x
        for i in range(self.size-1,0,-1):
            x = self.data[i+i]; y = self.data[i+i+1]
            self.data[i] = x if x>y else y
    
    def update(self,i,x):
        i += self.size
        self.data[i] = x
        i >>= 1
        while i:
            x = self.data[i+i]; y = self.data[i+i+1]
            self.data[i] = x if x>y else y
            i >>= 1
    
    def get_data(self,i):
        return self.data[i+self.size]

    def get_max(self,L,R):
        # [L,R] に対する値を返す
        L += self.size
        R += self.size + 1
        # [L,R) に変更
        x = 0
        while L < R:
            if L&1:
                y = self.data[L]
                if x < y: x = y
                L += 1
                
            if R&1:
                R -= 1
                y = self.data[R]
                if x < y: x = y
            L >>= 1; R >>= 1
        return x

"""
・あるから先を全て0で埋めた場合
・あるから先を全て1で埋めた場合
"""
add1 = [0] * (N+1)
add1[0] = sum(B)
for i,x in enumerate(B,1):
    if x:
        add1[i] = add1[i-1] - 1
    else:
        add1[i] = add1[i-1]
add0 = [N - i - x for i,x in enumerate(add1)]

add0,add1

# ある場所を最後の右端まで使ったとする。残りを全て 0 / 1 で埋めたときのスコア
dp0 = MaxSegTree([0] * (N+1))
dp1 = MaxSegTree([0] * (N+1))
dp0.update(0,add0[0])
dp1.update(0,add1[0])

for L,R in LR:
    a = dp1.get_data(R)
    b = dp0.get_max(0,L-1) + add1[L-1] - add0[L-1]
    c = dp1.get_max(L,R-1)
    if b < c:
        b = c
    if a < b:
        dp1.update(R, b)
        dp0.update(R, b - add1[R] + add0[R])

answer = N - dp0.get_max(0,N)
print(answer)