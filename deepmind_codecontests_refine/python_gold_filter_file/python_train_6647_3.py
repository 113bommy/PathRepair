import sys
N=int(input())
A=list(map(int,input().split()))
total=0
for i in range(N):
  total+=A[i]
if total*2/((N+1)*N)%1!=0:
  print("NO")
  sys.exit()
times=int(total*2/((N+1)*N))
if (times-A[0]+A[N-1])/N%1!=0 or times-A[0]+A[N-1]<0:
  print("NO")
  sys.exit()
B=(times-A[0]+A[N-1])/N
for i in range(N-1):
  B+=(times-A[i+1]+A[i])/N
  if (times-A[i+1]+A[i])/N%1!=0 or times-A[i+1]+A[i]<0:
    print("NO")
    sys.exit()
if B==times:
  print("YES")
else:
  print("NO")