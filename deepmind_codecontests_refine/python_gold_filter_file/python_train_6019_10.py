import sys
n=int(input())
c=[int(i) for i in sys.stdin]
#連続した数を除去したlist
d=[]
#前の数を保存する変数
stack=0
for i in c:
  if i!=stack:
    d.append(i)
  stack=i
#0で初期化
x=[0]*200001
sum=1
p=10**9+7
for i in range(0,len(d)):
  x[d[i]]= (x[d[i]]+sum)%p
  sum=x[d[i]]%p
print(sum)