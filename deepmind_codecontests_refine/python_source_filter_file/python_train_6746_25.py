import bisect
n=int(input())
A=[]
for i in range(n):
  A.append(int(input()))
Ans=[A[-1]]
for i in reversed(range(n-1)):
  a=A[i]
  if a>=Ans[-1]:
    Ans=Ans+[a]
  else:

    Ans[bisect.bisect_right(Ans,a)]=a

print(len(Ans))
