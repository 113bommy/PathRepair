n,k,x=map(int,input().split())
r=list(map(int,input().split()))
k%=48
while k:
  k-=1
  r.sort()
  for i in range(0,n,2):#alternate
    r[i]^=x
print(max(r),min(r))