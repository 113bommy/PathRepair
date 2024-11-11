n,a,b = map(int,input().split())
k = n//(a+b)
h = min(a,n%(a+b))
print(k+h)
