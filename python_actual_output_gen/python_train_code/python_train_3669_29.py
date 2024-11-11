x=list(map(int,input().split()))

n=x[0]
k=x[1]
t=x[2]

print(min(n,k,n+k-t))