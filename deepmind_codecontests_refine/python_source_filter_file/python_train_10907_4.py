x,k,d=map(int,input().split())
n=x//d
if k<n:n=k
r=x-n*d
if (k-n)%2:r-=d
print(abs(r))