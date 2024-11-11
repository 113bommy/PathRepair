def getIntList():
    return list(map(int, input().split()));
def getTransIntList(n):
    first=getIntList();
    m=len(first);
    result=[[0]*n for _ in range(m)];
    for i in range(m):
        result[i][0]=first[i];
    for j in range(1, n):
        curr=getIntList();
        for i in range(m):
            result[i][j]=curr[i];
    return result;
n, m, x, y, vx, vy=getIntList();
#Возвращает НОД d и коэффициенты k1, k2: k1*n1+k2*n2=d
def GCDKoef(n1, n2):
    k11=1;
    k12=0;
    k21=0;
    k22=1;
    while n2>0:
        k, r=divmod(n1, n2);
        n1, n2= n2, r;
        #r=n1-n2*k
        k11, k12, k21, k22 = k21, k22, k11 - k21 * k, k12 - k22*k;
    return n1, k11, k12;
def solveSystemCongruence(a1, n1, a2, n2):
    d, k1, k2=GCDKoef(n1, n2);
    if (a1-a2)%d!=0:
        return None;
    #t===a1(n1), t===a2(n2), d=GCD(n1, n2), d=n1*k1+n2*k2
    #r=a1%d=a2%d; a1=r+d*x1 a2=r+d*x2
    #t=r+x1*n2*k2+x2*n1*k1===r+d*x1=a1(n1) ===r+d*x2=a2(n2)
    r=a1%d;
    x1=(a1-r)//d;
    x2=(a2-r)//d;
    t=r+x1*n2*k2+x2*n1*k1;
    mod=n1*n2//d;
    t%=mod;
    if t<0:
        t+=mod;
    return t;
if vx==0:
    if x!=0 and x!=n:
        print(-1);
    elif vy==1:
        print(x, m)
    else:
        print(x, 0);
elif vy==0:
    if y!=0 and y!=m:
        print(-1);
    elif vx==1:
        print(n, y);
    else:
        print(n, 0);
else:
    t=solveSystemCongruence(-x*vx, n, -y*vy, m);
    if t==None:
        print(-1);
    else:
        x=x+t*vx;
        y=y+t*vy;
        x//=n;
        y//=m;
        x%=2;
        y%=2;
        x=abs(x);
        y=abs(y);
        print(x*n, y*m);