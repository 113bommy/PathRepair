N=int(input())
A= list(map(int,input().split()))
kin=[0]*N
gin=[0]*N
if N<=3:
 print(max(A))
else:
 kin[0]=A[0]
 kin[1]=A[1]
 kin[2]=kin[0]+A[2]
 gin[2]=A[2]
 for i in range(3,N):
  if i%2==1:
   kin[i]=max(kin[i-2],kin[i-3])+A[i]
  else:
   kin[i]=kin[i-2]+A[i]
   gin[i]=max(kin[i-3],gin[i-2])+A[i]
 if N%2==0:
  print(max(kin[N-1],kin[N-2]))
 else:
  print(max(gin[N-1],kin[N-2]))
