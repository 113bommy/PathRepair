import math
N=int(input())
number=list(map(int,input().split()))
SUM=[]
sum=0
p=10**9 +7
#Nの階乗
x=math.factorial(N)%p
#0からにすると1/0でエラーになる
for i in range(1,N+1):
  #kは逆元
  k=pow(i,p-2,p)
  sum+= (x*k)%p
  sum= sum%p
  SUM.append(sum)
#SUMのi番目は1/1から1/iまで足した和になっている。
#k=i-1となる
#1/1を二回足してしまったので引く
for i in range(N):
  ans+= (number[i]*(SUM[i]+SUM[N-i-1]-x))%p
  ans= ans%p
#答え
print(ans)