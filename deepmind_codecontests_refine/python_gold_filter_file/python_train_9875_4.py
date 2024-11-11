import collections
import heapq
n=int(input())
A=[int(i) for i in input().split()]
Ans=[0]*n
M=[0]#自分より前の最大値をメモ。これ以下だと現れない
for i in range(n):
  M.append(max(M[-1],A[i]))
D=collections.defaultdict(int)
H=[]
for i in range(n):
  j=n-1-i
  if A[j]<=M[j]:
    heapq.heappush(H,-A[j])#出現しないインデックスの数を管理。大きいほうから取り出す。
  else:
    Ans[j]=(A[j]-M[j])*(D[A[j]]+1)#自分より前の最大値と自分の差かける自分自身と同じ数のこれまでの出現回数
    D[M[j]]+=D[A[j]]+1#自分自身より後ろの自分と同じ数全てを自分より前の最大値まで減らすことで増える分
    ct=0
    while H:#自分より後ろで自分より小さいが、自分の前の最大値より大きいものを全て見る
      a=heapq.heappop(H)
      a=-a
      if a<=M[j]:
        heapq.heappush(H,-a)
        break
      else:
        Ans[j]+=a-M[j]
        D[M[j]]+=1

for a in Ans:
  print(a)
