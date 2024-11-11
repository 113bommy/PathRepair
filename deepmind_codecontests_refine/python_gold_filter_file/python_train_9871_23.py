class SegTree():
    def __init__(self,size,unit,f):
        self.size=size
        self.data=[unit for _ in range(2*size)]
        self.unit=unit
        self.f=f
    def update(self,i,x):
        c,f=self.data,self.f
        i+=self.size
        c[i]=f(c[i],x)
        while i>1:
            i>>=1
            c[i]=f(c[i+i],c[i-~i])
    def query(self,l,r):
        c,f=self.data,self.f
        x,y=self.unit,self.unit
        l+=self.size
        r+=self.size
        while l<r:
            if l&1:
                x=f(x,c[l])
                l+=1
            if r&1:
                r-=1
                y=f(c[r],y)
            l>>=1
            r>>=1
        return f(x,y)
def main():
    n,*a=map(int,open(0).read().split())
    dp=SegTree(n+1,0,lambda a,b:a if a>b else b)
    for h,a in zip(a,a[n:]):dp.update(h,dp.query(0,h)+a)
    print(dp.data[1])
main()