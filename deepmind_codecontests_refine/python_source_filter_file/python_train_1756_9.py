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
from itertools import accumulate,combinations,permutations#累積和
#list(accumulate(l))
from heapq import heapify,heappop,heappush
#heapify(q),heappush(q,a),heappop(q) #q=heapify(q)としないこと、返り値はNone
#import fractions#古いatcoderコンテストの場合GCDなどはここからimportする
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
class multiset:#同じ要素を複数持てる
    def __init__(self,x=None):#最大値を取り出したいときはクラスの外でマイナスを処理する
        if x==None:
            self.counter=Counter()
            self.q=[]
        else:
            self.counter=Counter(x)
            self.q=list(x)
            heapify(self.q)
    def add(self,a):
        self.counter[a]+=1
        heappush(self.q,a)
    def remove(self,a):
        if self.counter[a]:
            self.counter[a]-=1
            return 1
        else:
            return 0
    def min(self):
        while not self.counter[self.q[0]]:
            heappop(self.q)
        return self.q[0]
    def pop(self):
        while self.q and self.counter[self.q[0]]==0:
            heappop(self.q)
        if self.q:
            self.counter[self.q[0]]-=1
            return heappop(self.q)
        return None
    def __eq__(self,other):
        return other.counter==self.counter
    def __len__(self): return len(self.q)

def main():
    mod = 1000000007
    #w.sort(key=itemgetter(1),reverse=True)  #二個目の要素で降順並び替え

    N = int(input())
    #N, K = map(int, input().split())
    A = tuple(map(int, input().split())) #1行ベクトル
    #L = tuple(int(input()) for i in range(N)) #改行ベクトル
    #S = tuple(tuple(map(int, input().split())) for i in range(N)) #改行行列
    ms=multiset(A)
    ma=max(A)
    for i in range(ma+1):
        t=max(i,ma-i)
        f=ms.remove(t)
        if not f:
            print("Imporssible")
            return
    
    sles=math.ceil(ma*0.5)+1
    while True:
        x=ms.pop()
        if x==None:
            break

        if x>=sles:
            continue
        else:
            print("Impossible")
            return
    print("Possible")
    




if __name__ == "__main__":
    main()