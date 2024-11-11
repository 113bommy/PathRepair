p=int(input())
A=list(map(int,input().split()))
cmb=[0]*p
cmb[0]=1
for i in range(1,p):
  cmb[i]=cmb[i-1]*(p-i)*pow(i,p-2,p)%p
ans=[0]*p
for i in range(p):
  if A[i]==1:
    b=1
    ans[0]=ans[0]+1
    for j in range(p):
      ans[p-j-1]=(ans[p-j-1]-cmb[j]*b)%p
      b=b*(-i)%p
for i in range(p-1):
  print(ans[i],end=" ")
print(ans[p-1])

