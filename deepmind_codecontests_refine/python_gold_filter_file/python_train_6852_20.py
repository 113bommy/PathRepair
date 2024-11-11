class BIT:
    def __init__(self,n):
        self.size=n
        self.tree=[0]*-~n
    def sum(self,i):
        s=0
        while i:
            s+=self.tree[i]
            i-=i&-i
        return s
    def add(self,i,x):
        while i<=self.size:
            self.tree[i]+=x
            i+=i&-i
n,*a=map(int,open(0).read().split())
m=n*-~n//2+1>>1
ng=max(a)+1
ok=0
while ng-ok>1:
    mid=(ok+ng)//2
    b=BIT(n-~n)
    c=n+1
    s=0
    b.add(c,1)
    for t in a:
        c+=1if t>=mid else-1
        s+=b.sum(c)
        b.add(c,1)
    if s>=m:ok=mid
    else:ng=mid
print(ok)