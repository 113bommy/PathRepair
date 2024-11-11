N,M,K= (int(i) for i in input().split())  
ok=0

for j in range(M):
 for i in range(N):
  if j*N+i*M-2*i*j==K :

       ok=1

if ok==0:
 print("No")
else:
 print("Yes")