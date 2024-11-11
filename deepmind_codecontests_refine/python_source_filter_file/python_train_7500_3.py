import math

class SegmentTree():
    def __init__(self, n):
        self.n = n
        self.height = math.ceil(math.log2(n))
        self.nodes = [0 for i in range(pow(2, self.height+1)-1)]
        self.leaf_start = pow(2, self.height)-1

    def update(self, i, x):
        pntr = self.leaf_start + i
        self.nodes[pntr] += x
        while True:
            pntr = (pntr-1)//2
            if pntr == -1: break
            self.nodes[pntr] += x

    def __query(self, s, t, k, l, r):
        if t - s <= 0: return 0
        if r <= s or t <= l: return 0
        if l == s and t == r: return self.nodes[k]
        else:
            m = (l+r)//2
            if t <= m:
                return self.__query(s, t, k*2+1, l, m)
            elif m <= s:
                return self.__query(s, t, k*2+2, m, r)
            else:
                vl = self.__query(s, m, k*2+1, l, m)
                vr = self.__query(m, t, k*2+2, m, r)
                return vl + vr

    def find(self, s, t):
        return self.__query(s, t+1, 0, 0, pow(2, self.height))

n, q = list(map(int, input().split(' ')))
st = SegmentTree(n)
for i in range(q):
    com, x, y = list(map(int, input().split(' ')))
    if com == 0:
        st.update(x-1, y)
    elif com == 1:
        print(st.find(x, y))
