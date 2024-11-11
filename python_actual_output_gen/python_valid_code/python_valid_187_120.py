n,a,b = map(int,input().split())
print((n//(a+b))*a + max(0,n%(a+b)-b))