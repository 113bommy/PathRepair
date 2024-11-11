k=int(input())
n=50
q,r=k//n,k%n
a=[n-1-k+q*(n+1)]*n
a=list(map(lambda x:x+n+1,a[0:r-1]))+a[r:n-1]
print(n)
print(' '.join(map(str,a)))