class SWAG():
    def __init__(self,unit,f):
        self.fold_r=[unit]
        self.fold_l=[unit]
        self.data_r=[]
        self.data_l=[]
        self.f=f
    def __refill_right(self):
        temp=[]
        n=len(self.data_l)
        *_,=map(temp.append,(self.popleft()for _ in range(n//2)))
        *_,=map(self.append,(self.popleft()for _ in range(n//2,n)))
        *_,=map(self.appendleft,temp[::-1])
    def __refill_left(self):
        temp=[]
        n=len(self.data_r)
        *_,=map(temp.append,(self.pop()for _ in range(n//2)))
        *_,=map(self.appendleft,(self.pop()for _ in range(n//2,n)))
        *_,=map(self.append,temp[::-1])
    def append(self,x):
        self.fold_r.append(self.f(self.fold_r[-1],x))
        self.data_r.append(x)
    def appendleft(self,x):
        self.fold_l.append(self.f(self.fold_l[-1],x))
        self.data_l.append(x)
    def pop(self):
        if not self.data_r:
            self.__refill_right()
        self.fold_r.pop()
        return self.data_r.pop()
    def popleft(self):
        if not self.data_l:
            self.__refill_left()
        self.fold_l.pop()
        return self.data_l.pop()
    def fold_all(self):
        return self.f(self.fold_r[-1],self.fold_l[-1])
n,k,*p=map(int,open(0).read().split())
c=[0]
for a,b in zip(p,p[1:]):c+=c[-1]+(a<b),
*c,f=[b-a==k-1for a,b in zip(c,c[k-1:])]
x=not f
s_min=SWAG(10**18,min)
s_max=SWAG(0,max)
*_,=map(s_min.append,p[:k-1])
*_,=map(s_max.append,p[1:k])
for i,(a,b,c)in enumerate(zip(p,p[k:],c)):
    f|=c
    s_min.append(p[i+k-1])
    s_max.append(b)
    if not c and(a!=s_min.fold_all()or b!=s_max.fold_all()):x+=1
    s_min.popleft()
    s_max.popleft()
print(x+f)