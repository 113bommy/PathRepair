#参考URL
#https://qiita.com/ageprocpp/items/104c051b2ec2086f5a9b

mod=10**9+7
def value(obj):
    if type(obj)==modint:
        tmp=obj.number
    else:
        tmp=obj
    return tmp%mod
class modint():
    number=0
    def __init__(self,num):
        self.number=num%mod
    def __add__(self,other):
        tmp=value(other)
        return modint(self.number+tmp)
    def __iadd__(self,other):
        tmp=value(other)
        self.number+=tmp
        self.number%=mod
        return self
    def __sub__(self,other):
        tmp=value(other)
        return modint(self.number-tmp)
    def __isub__(self,other):
        tmp=value(other)
        self.number-=tmp
        self.number%=mod
        return self
    def __mul__(self,other):
        tmp=value(other)
        return modint(self.number*tmp)
    def __imul__(self,other):
        tmp=value(other)
        self.number*=tmp
        self.number%=mod
        return self
    def __truediv__(self,other):
        tmp=value(other)
        return self*pow(tmp,mod-2,mod)
    def __itruediv(self,other):
        tmp=value(other)
        self.number=self/tmp
        self.number%=mod
        return self
    def __repr__(self):
        return str(self.number)
    def __eq__(self,other):
        return value(self)==value(other)
    def __ne__(self,other):
        return value(self)!=value(other)
    def __str__(self):
        return str(self.number)
    def __int__(self):
        return self.number
    def __hash__(self):
        return self.number

class polynomial():
    sequence=[0]
    def __init__(self,seq):
        self.sequence=[]
        for i in seq:
            self.sequence.append(value(i))
    def get(self,x):
        res=modint(0)
        tmp=modint(1)
        for a in self.sequence:
            res+=tmp*a
            tmp*=x
            if tmp==0:
                break
        return res
    def __add__(self,other):
        res=[]
        for i,a in enumerate(self.sequence):
            try:
                res[i]=a
            except IndexError:
                res.append(modint(0))
                res[i]=a
        for i,a in enumerate(other.sequence):
            try:
                res[i]+=a
            except IndexError:
                res.append(modint(0))
                res[i]+=a
        
        return polynomial(res)
    def __iadd__(self,other):
        return self+other
    def __sub__(self,other):
        res=[]
        for i,a in enumerate(self.sequence):
            try:
                res[i]=a
            except IndexError:
                res.append(modint(0))
                res[i]=a
        for i,a in enumerate(other.sequence):
            try:
                res[i]-=a
            except IndexError:
                res.append(modint(0))
                res[i]-=a
        return polynomial(res)
    def __isub__(self,other):
        return self-other
    def indef_integral(self):
        res=[modint(0)]
        for i,a in enumerate(self.sequence):
            res.append(modint(a)/(i+1))
        return polynomial(res)
    def integrate(self,flag):
        #0: 0->x
        #1:x->1
        if flag==0:
            return self.indef_integral()
        else:
            tmp=self.indef_integral()
            return polynomial([tmp.get(1)])-tmp
    def __repr__(self):
        return str(self.sequence)
    def __str__(self):
        return str(self.sequence)

class func():
    P=polynomial([modint(0)])
    Q=polynomial([modint(0)])
    C=modint(0)
    def __init__(self,poly1,poly2,cnst):
        self.P=poly1
        self.Q=poly2
        self.C=cnst
    def __add__(self,other):
        PP=self.P+other.P
        QQ=self.Q+other.Q
        CC=self.C+other.C
        return func(PP,QQ,CC)
    def __iadd__(self,other):
        return self+other
    def __sub__(self,other):
        PP=self.P-other.P
        QQ=self.Q-other.Q
        CC=self.C-other.C
        return func(PP,QQ,CC)
    def __isub__(self,other):
        return self-other
    def dintegrate(self,flag):
        if flag==0:
            PP=self.P.integrate(0)+polynomial([self.C])
            QQ=self.Q.integrate(0)
            CC=modint(-1)*self.C
        else:
            PP=self.P.integrate(1)
            QQ=self.Q.integrate(1)+polynomial([modint(-1)*self.C])
            CC=self.C
        return func(PP,QQ,CC)
MAX_N=1009
N=int(input())
s=input()
fact=[modint(0) for i in range(MAX_N+1)]
inv=[modint(0) for i in range(MAX_N+1)]
fact[0]=modint(1)
for i in range(MAX_N):
    fact[i+1]=fact[i]*(i+1)
inv[-1]=modint(1)/fact[-1]
for i in range(MAX_N-1,-1,-1):
    inv[i]=inv[i+1]*(i+1)
dp=[[[[func(polynomial([modint(0)]),polynomial([modint(0)]),modint(0)) for l in range(2)]for k in range(2)]for j in range(2)] for i in range(MAX_N+1)]

if s[0]=="X":
    dp[0][0][1][0]=func(polynomial([modint(0)]),polynomial([modint(0)]),modint(1))
else:
    dp[0][0][0][1]=func(polynomial([modint(0)]),polynomial([modint(0)]),modint(1))
    dp[0][1][1][1]=func(polynomial([modint(1)]),polynomial([modint(0)]),modint(-1))
for i in range(1,N):
    if s[i]=="X":
        dp[i][0][1][0]+=dp[i-1][1][1][0].dintegrate(0)
        dp[i][0][1][0]+=dp[i-1][1][1][1].dintegrate(0)
        dp[i][0][1][0]+=dp[i-1][0][0][1].dintegrate(1)
        dp[i][0][1][0]+=dp[i-1][0][1][1].dintegrate(1)
        dp[i][0][1][0]+=dp[i-1][1][0][1].dintegrate(1)
        dp[i][0][1][0]+=dp[i-1][1][1][1].dintegrate(1)
    else:
        dp[i][0][0][1]+=dp[i-1][1][1][0].dintegrate(0)
        dp[i][0][0][1]+=dp[i-1][1][1][1].dintegrate(0)
        dp[i][1][1][1]+=dp[i-1][0][1][0].dintegrate(0)
        dp[i][1][1][1]+=dp[i-1][0][1][1].dintegrate(0)
        dp[i][0][0][1]+=dp[i-1][0][1][0].dintegrate(1)
        dp[i][0][0][1]+=dp[i-1][0][1][1].dintegrate(1)
        dp[i][0][0][1]+=dp[i-1][1][1][0].dintegrate(1)
        dp[i][0][0][1]+=dp[i-1][1][1][1].dintegrate(1)
a=modint(0)
b=modint(0)
c=modint(0)

p = dp[N-1][0][1][1].P.integrate(0)
a+= p.get(1)-p.get(0)
p = dp[N-1][0][1][1].Q.integrate(0)
b+= p.get(1)-p.get(0)
a+= dp[N-1][0][1][1].C
b-= dp[N-1][0][1][1].C
p = dp[N-1][1][1][1].P.integrate(0)
a+= p.get(1)-p.get(0)
p = dp[N-1][1][1][1].Q.integrate(0)
b+= p.get(1)-p.get(0)
a+= dp[N-1][1][1][1].C
b-= dp[N-1][1][1][1].C
for x in range(2):
    for i,v in enumerate(dp[N-1][x][1][0].P.sequence):
        a+=modint(1)*v*fact[i]
        for j in range(i+1):
            b-=modint(1)*v*fact[i]*inv[j]
    for i,v in enumerate(dp[N-1][x][1][0].Q.sequence):
        b+=modint(1)*v*fact[i]
        for j in range(i+1):
            c-=modint(1)*v*fact[i]*inv[j]
    a+=dp[N-1][x][1][0].C/2
    c-=dp[N-1][x][1][0].C/2

p = dp[N-1][0][0][1].P.integrate(0)
a+= p.get(1)-p.get(0)
p = dp[N-1][0][0][1].Q.integrate(0)
b+= p.get(1)-p.get(0)
a+= dp[N-1][0][0][1].C
b-= dp[N-1][0][0][1].C
p = dp[N-1][1][0][1].P.integrate(0)
a+= p.get(1)-p.get(0)
p = dp[N-1][1][0][1].Q.integrate(0)
b+= p.get(1)-p.get(0)
a+= dp[N-1][1][0][1].C
b-= dp[N-1][1][0][1].C
for x in range(2):
    for i,v in enumerate(dp[N-1][x][0][1].P.sequence):
        a-=modint(1)*v*fact[i]
        for j in range(i+1):
            b+=modint(1)*v*fact[i]*inv[j]
    for i,v in enumerate(dp[N-1][x][0][1].Q.sequence):
        b-=modint(1)*v*fact[i]
        for j in range(i+1):
            c+=modint(1)*v*fact[i]*inv[j]
    a-=dp[N-1][x][0][1].C/2
    c+=dp[N-1][x][0][1].C/2

print(a,b,c)

            
