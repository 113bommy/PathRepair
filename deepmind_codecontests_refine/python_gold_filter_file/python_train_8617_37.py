class SegmentTree:
    def __init__(self,n):
        self.siz = 1
        while self.siz < n: self.siz *= 2
        self.node = [0]*(2*self.siz-1)

    def update(self,i,x):
        i += self.siz-1
        self.node[i] = x
        while i > 0:
            i = (i-1)//2
            self.node[i] = self.node[i*2+1] | self.node[i*2+2]
    
    def query(self,a,b,k=0,l=0,r=-1):
        if r < 0: r = self.siz
        if r <= a or b <= l: return 0
        if a <= l and r <= b: return self.node[k]
        vl = self.query(a,b,k*2+1,l,(l+r)//2)
        vr = self.query(a,b,k*2+2,(l+r)//2,r)
        return vl | vr
    
n = int(input())
st = SegmentTree(n)
s = list(input())
def f(c): return 1<<(ord(c) - ord("a"))
for i in range(n): st.update(i,f(s[i]))
q = int(input())
for _ in range(q):
    typ,x,y = input().split()
    if typ == "1":
        i,c = int(x)-1,y
        if s[i] == c: continue
        st.update(i,f(c))
        s[i] = c
    else:
        l,r = int(x)-1,int(y)
        print(bin(st.query(l,r)).count("1"))