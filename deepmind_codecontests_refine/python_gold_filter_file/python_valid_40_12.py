import sys
read=sys.stdin.buffer.read;readline=sys.stdin.buffer.readline;input=lambda:sys.stdin.readline().rstrip()
import bisect,string,math,time,functools,random,fractions
from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
from itertools import permutations,combinations,groupby
rep=range;R=range
def I():return int(input())
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def NLI(n):return [[int(i) for i in input().split()] for i in range(n)]
def NLI_(n):return [[int(i)-1 for i in input().split()] for i in range(n)]
def StoLI():return [ord(i)-97 for i in input()]
def ItoS(n):return chr(n+97)
def LtoS(ls):return ''.join([chr(i+97) for i in ls])
def RLI(n=8,a=1,b=10):return [random.randint(a,b)for i in range(n)]
def RI(a=1,b=10):return random.randint(a,b)
def INP():
    N=9
    n=random.randint(1,N)
    A=[random.randint(1,n) for i in range(m)]
    return n,A
def Rtest(T):
    case,err=0,0
    for i in range(T):
        inp=INP()
        a1=naive(*inp)
        a2=solve(*inp)
        if a1!=a2:
            print(inp)
            print('naive',a1)
            print('solve',a2)
            err+=1
        case+=1
    print('Tested',case,'case with',err,'errors')
def GI(V,E,ls=None,Directed=False,index=1):
    org_inp=[];g=[[] for i in range(V)]
    FromStdin=True if ls==None else False
    for i in range(E):
        if FromStdin:
            inp=LI()
            org_inp.append(inp)
        else:
            inp=ls[i]
        if len(inp)==2:a,b=inp;c=1
        else:a,b,c=inp
        if index==1:a-=1;b-=1
        aa=(a,c);bb=(b,c);g[a].append(bb)
        if not Directed:g[b].append(aa)
    return g,org_inp
def GGI(h,w,search=None,replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1):
    #h,w,g,sg=GGI(h,w,search=['S','G'],replacement_of_found='.',mp_def={'#':1,'.':0},boundary=1) # sample usage
    mp=[boundary]*(w+2);found={}
    for i in R(h):
        s=input()
        for char in search:
            if char in s:
                found[char]=((i+1)*(w+2)+s.index(char)+1)
                mp_def[char]=mp_def[replacement_of_found]
        mp+=[boundary]+[mp_def[j] for j in s]+[boundary]
    mp+=[boundary]*(w+2)
    return h+2,w+2,mp,found
def TI(n):return GI(n,n-1)
def accum(ls):
    rt=[0]
    for i in ls:rt+=[rt[-1]+i]
    return rt
def bit_combination(n,base=2):
    rt=[]
    for tb in R(base**n):s=[tb//(base**bt)%base for bt in R(n)];rt+=[s]
    return rt
def gcd(x,y):
    if y==0:return x
    if x%y==0:return y
    while x%y!=0:x,y=y,x%y
    return y
def YN(x):print(['NO','YES'][x])
def Yn(x):print(['No','Yes'][x])
def show(*inp,end='\n'):
    if show_flg:print(*inp,end=end)

mo=10**9+7
#mo=998244353
inf=1<<63
FourNb=[(-1,0),(1,0),(0,1),(0,-1)];EightNb=[(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)];compas=dict(zip('WENS',FourNb));cursol=dict(zip('LRUD',FourNb))
alp=[chr(ord('a')+i)for i in range(26)]
#sys.setrecursionlimit(10**7)

show_flg=False
show_flg=True


########################################################################################################################################################################
# Verified by
# https://yukicoder.me/problems/no/979
# https://atcoder.jp/contests/abc152/tasks/abc152_e

## return prime factors of N as dictionary {prime p:power of p}
## within 2 sec for N = 2*10**20+7
def primeFactor(N):
    i,n=2,N
    ret={}
    d,sq=2,99
    while i<=sq:
        k=0
        while n%i==0:
            n,k,ret[i]=n//i,k+1,k+1
        if k>0 or i==97:
            sq=int(n**(1/2)+0.5)
        if i<4:
            i=i*2-1
        else:
            i,d=i+d,d^6
    if n>1:
        ret[n]=1
    return ret

## return divisors of n as list
def divisors(n):
    div=[1]
    for i,j in primeFactor(n).items():
        div=[(i**k)*d for d in div for k in range(j+1)]
    return div

## return the array s such that s[q] = the minimum prime factor of q
def sieve(x):
    s=[i for i in range(x+1)]
    p=2
    while p*p<=x:
        if s[p]==p:
            for q in range(2*p,x+1,p):
                if s[q]==q:
                    s[q]=p
        p+=1
    return s

## return the list of prime numbers in [2,N], using eratosthenes sieve
## around 800 ms for N = 10**6  by PyPy3 (7.3.0) @ AtCoder
def PrimeNumSet(N):
    M=int(N**0.5)
    seachList=[i for i in range(2,N+1)]
    primes=[]
    while seachList:
        if seachList[0]>M:
            break
        primes.append(seachList[0])
        tmp=seachList[0]
        seachList=[i for i in seachList if i%tmp!=0]
    return primes+seachList


## retrun LCM of numbers in list b
## within 2sec for no of B = 10*5  and  Bi < 10**6
def LCM(b,mo=10**9+7):
    prs=PrimeNumSet(max(b))
    M=dict(zip(prs,[0]*len(prs)))
    for i in b:
        dc=primeFactor(i)
        for j,k in dc.items():
            M[j]=max(M[j],k)
    
    r=1
    for j,k in M.items():
        if k!=0:
            r*=pow(j,k,mo)
            r%=mo
    return r

## return (a,b,gcd(x,y)) s.t. a*x+b*y=gcd(x,y)
def extgcd(x,y):
    if y==0:
        return 1,0
    r0,r1,s0,s1 = x,y,1,0
    while r1!= 0:
        r0,r1,s0,s1=r1,r0%r1,s1,s0-r0//r1*s1
    return s0,(r0-s0*x)//y,x*s0+y*(r0-s0*x)//y


## return x,LCM(mods) s.t. x = rem_i (mod_i), x = -1 if such x doesn't exist
## verified by ABC193E
## https://atcoder.jp/contests/abc193/tasks/abc193_e
def crt(rems,mods):
    n=len(rems)
    if n!=len(mods):
        return NotImplemented
    x,d=0,1
    
    for r,m in zip(rems,mods):
        a,b,g=extgcd(d,m)
        x,d=(m*b*x+d*a*r)//g,d*(m//g)
        x%=d

    for r,m in zip(rems,mods):
        if r!=x%m:
            return -1,d

    return x,d

## returns the maximum integer rt s.t. rt*rt<=x
## verified by ABC191D
## https://atcoder.jp/contests/abc191/tasks/abc191_d
def intsqrt(x):
    if x<0:
        return NotImplemented
    rt=int(x**0.5)-1
    while (rt+1)**2<=x:
        rt+=1
    return rt
    
ans=0


for _ in range(I()):
    n=I()
    a=LI()
    b=LI()
    ans=d=sum(b[:n-1])
    u=0
    for i in range(n-2,-1,-1):
        d-=b[i]
        u+=a[i+1]
        ans=min(ans,max(u,d))
    print(ans)

