N=int(input())
P=list(map(int,input().split()))
I=[0]*N
for i,p in enumerate(P):
    I[N-p]=i
class BIT:
    def __init__(self,size):
        self.N=size
        self.v=[0]*(self.N+1)
    def add(self,i,x):
        i+=1
        while i<=self.N:
            self.v[i]+=x
            i+=i&-i
    def sum(self,a,b=0):
        if a>b:
            a,b=b,a
        if a>0:
            r=self.sum(b)-self.sum(a)
        else:
            r=0
            i=b
            while i>0:
                r+=self.v[i]
                i-=i&-i
        return r
    def right(self,x):
        a,b=x+1,self.N
        while a+1<b:
            t=(a+b)//2
            if self.sum(a,t)>0:
                b=t
            else:
                a=t
        return a 
    def left(self,x):
        a,b=0,x
        while a+1<b:
            t=(a+b)//2
            if self.sum(t,b)>0:
                a=t
            else:
                b=t
        return a
b=BIT(2**14)
b.add(0,N+1)
b.add(1,N+1)
b.add(N+2,N+1)
b.add(N+3,N+1)
a=0
p=N
for i in I:
    l=b.left(i+2)
    ll=b.left(l)
    r=b.right(i+2)
    rr=b.right(r)
    if 1<l and r<N+2:
        a+=((l-ll)*(r-i-2)+(rr-r)*(i+2-l))*p
    elif 1<l:
        a+=(l-ll)*(N-i)*p
    elif r<N+2:
        a+=(rr-r)*(i+1)*p
    b.add(i+2,p)
    p-=1
print(a)