import sys
sys.setrecursionlimit(10**7) #再帰関数の上限,10**5以上の場合python
import math
from copy import copy, deepcopy
from copy import deepcopy as dcp
from operator import itemgetter
from bisect import bisect_left, bisect, bisect_right#2分探索
#bisect_left(l,x), bisect(l,x)#aはソート済みである必要あり。aの中からx未満の要素数を返す。rightだと以下
from collections import deque, defaultdict
#deque(l), pop(), append(x), popleft(), appendleft(x)
#q.rotate(n)で → にn回ローテート
from collections import Counter#文字列を個数カウント辞書に、
#S=Counter(l),S.most_common(x),S.keys(),S.values(),S.items()
from itertools import accumulate,combinations,permutations,product#累積和
#list(accumulate(l))
from heapq import heapify,heappop,heappush
#heapify(q),heappush(q,a),heappop(q) #q=heapify(q)としないこと、返り値はNone
from functools import reduce,lru_cache#pypyでもうごく
#@lru_cache(maxsize = None)#maxsizeは保存するデータ数の最大値、2**nが最も高効率
from decimal import Decimal

def input(): 
    x=sys.stdin.readline()
    return x[:-1] if x[-1]=="\n" else x
def printe(*x):print("## ",*x,file=sys.stderr)
def printl(li): _=print(*li, sep="\n") if li else None
def argsort(s, return_sorted=False): 
    inds=sorted(range(len(s)), key=lambda k: s[k])
    if return_sorted: return inds, [s[i] for i in inds]
    return inds
def alp2num(c,cap=False): return ord(c)-97 if not cap else ord(c)-65
def num2alp(i,cap=False): return chr(i+97) if not cap else chr(i+65)
def matmat(A,B):
    K,N,M=len(B),len(A),len(B[0])
    return [[sum([(A[i][k]*B[k][j]) for k in range(K)]) for j in range(M)] for i in range(N)]
def matvec(M,v):
    N,size=len(v),len(M)
    return [sum([M[i][j]*v[j] for j in range(N)]) for i in range(size)]
def T(M):
    n,m=len(M),len(M[0])
    return [[M[j][i] for j in range(n)] for i in range(m)]
def binr(x): return bin(x)[2:]
def bitcount(x): #xは64bit整数
    x= x - ((x >> 1) & 0x5555555555555555)
    x= (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x= (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f 
    x+= (x >> 8); x+= (x >> 16); x+= (x >> 32) 
    return x & 0x7f
import random
class rh:#base,max_n=ありうる文字の最大長,convertを指定すること
    def __init__(self,base,max_n):#baseとmaxnを指定すること。baseは偶数(modが奇数)
        self.mod=random.randrange(1<<54-1,1<<55-1,2)#奇数、衝突させられないよう乱数で生成
        self.base=int(base*0.5+0.5)*2#偶数,英小文字なら26とか
        self.max_n=max_n
        self.pows1=[1]*(max_n+1)
        cur1=1
        for i in range(1,max_n+1):
            cur1=cur1*base%self.mod
            self.pows1[i]=cur1

    def convert(self,c): return alp2num(c,False)#大文字の場合Trueにする
    
    def get(self, s):#特定の文字のhash. O(|s|)
        n=len(s)
        mod=self.mod
        si=[self.convert(ss) for ss in s]
        h1=0
        for i in range(n):h1=(h1+si[i]*self.pows1[n-1-i])%mod
        return h1
    
    def get_roll(self, s, k, uroboros=False):#ローリングハッシュ,sの各文字を始点とした長さkの部分文字のhash値をすべて得る,O(|s|)
        #uroboros: trueの場合文字sを循環させ、n個のハッシュ値を得る。 falseの場合n-k+1個
        n=len(s)
        maxitr=n-k+1
        if uroboros: maxitr=n
    
        si=[self.convert(ss) for ss in s]
        mod=self.mod
        h1=0
        for i in range(k):h1=(h1+si[i%n]*self.pows1[k-1-i])%mod
        hs=[0]*maxitr
        hs[0]=h1
        mbase1=self.pows1[k]
        base=self.base
        
        for i in range(1,maxitr): 
            front=si[i-1];back=si[(i+k-1)%n]
            h1=(h1*base-front*mbase1+back)%mod
            hs[i]=h1
        return hs

def main():
    mod = 1000000007
    #w.sort(key=itemgetter(1),reverse=True)  #二個目の要素で降順並び替え

    N = int(input())
    mod=1000000007
    mod2=999999937
    #N, K = map(int, input().split())
    #A = tuple(map(int, input().split())) #1行ベクトル
    L=["" for _ in range(N)]
    ll=[0]*N
    for i in range(N):
        s=input()
        ls=len(s)
        ll[i]=ls
        L[i]=s

    #S = tuple(tuple(map(int, input().split())) for i in range(N)) #改行行列

    inds=argsort(ll)
    d=Counter()
    ans=0
    base=27

    for im in inds:
        
        s=L[im]

        ls=len(s)
        cur=0
        cur2=0
        se=Counter(s)
        #printe(se)
        for i in range(ls):
            for a,val in se.items():
                if val:
                    ai=alp2num(a)
                    ans+=d[((cur*base+ai)%mod,(cur2*base+ai)%mod2)]
                    
            si=s[-1-i]
            sin=alp2num(si)
            cur=(cur*base+sin)%mod
            cur2=(cur2*base+sin)%mod2
            se[si]-=1

        d[(cur,cur2)]+=1

    print(ans)
            





if __name__ == "__main__":
    main()