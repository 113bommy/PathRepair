import sys,bisect,string,math,time,functools,random,fractions
from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
from itertools import permutations,combinations,groupby
rep=range;R=range
def Golf():n,*t=map(int,open(0).read().split())
def I():return int(input())
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def MI():return map(int,input().split())
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def StoLI():return [ord(i)-97 for i in input()]
def ItoS(n):return chr(n+97)
def LtoS(ls):return ''.join([chr(i+97) for i in ls])
def RA():return map(int,open(0).read().split())
def RLI(n=8,a=1,b=10):return [random.randint(a,b)for i in range(n)]
def RI(a=1,b=10):return random.randint(a,b)
def Rtest(T):
    case,err=0,0
    for i in range(T):
        inp=INP()
        a1,ls=naive(*inp)
        a2=solve(*inp)
        if a1!=a2:
            print((a1,a2),inp)
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
        if len(inp)==2:
            a,b=inp;c=1
        else:
            a,b,c=inp
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
inf=float('inf')
FourNb=[(-1,0),(1,0),(0,1),(0,-1)];EightNb=[(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)];compas=dict(zip('WENS',FourNb));cursol=dict(zip('LRUD',FourNb))
l_alp=string.ascii_lowercase
#sys.setrecursionlimit(10**9)
read=sys.stdin.buffer.read;readline=sys.stdin.buffer.readline;input=lambda:sys.stdin.readline().rstrip()


show_flg=False
show_flg=True

ans=0



for _ in range(I()):
    n=I()
    a=[1 if i=='R' else 0 for i in input()]
    x=a.count(1)
    ans=0
    if a[0]==0:
        for i in range(n):
            if a[i]==1:
                a=a[i:]+a[:i]
                break
    else:
        for i in range(n)[::-1]:
            if a[i]==0:
                a=a[i+1:]+a[:i+1]
                break
    
    if x==n:
        a[-1]=0
        ans=1
    elif x==0:
        a[0]=1
        ans=1
    
    for k,d in groupby(a):
        nd=len(list(d))
        #show(k,nd)
        ans+=nd//3
    print(ans)#,a,'ans')

    
