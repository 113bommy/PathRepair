N=int(input())
a=list(map(int,input().split()))
b=[]
b2=[]
if N%2==0:
  for i in range(0,N,2):
    b.append(str(a[N-i-1]))
    b2.append(str(a[i]))
  ans=b+b2
else:
  for i in range(N):
    if i%2==0:
      b.append(str(a[N-1-i]))
    else:
      b.append(str(a[i]))
  ans=b
print(' '.join(ans))