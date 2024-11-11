from math import factorial as f
n,m,k=map(int,input().strip().split())
print((f(n*m-2)//(f(k-2)*f(n*m-k))*(m*m*(n**3-n)+n*n*(m**3-m))//6)%(10**9+7))