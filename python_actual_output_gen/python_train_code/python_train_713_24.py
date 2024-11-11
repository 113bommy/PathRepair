n,m,k=map(int,input().split())
if k<n:i,j=1+k,1
elif k>n:
 k-=n;l=2*(m-1);i=n-k//l*2;k%=l
 if k<n-1:j=2+k
 else:
  i-=1;j=m-k+n-2
else:i,j=n,2
print(i,j)