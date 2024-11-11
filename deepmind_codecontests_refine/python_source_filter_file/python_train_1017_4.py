n,k,s=map(int,input().split())
l=[s]*k
if s==1:
 l+=[s+1]*(n-k)
else:
 l+=[s-1]*(n-k)
print(l)