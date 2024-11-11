n,k,t=map(int,input().split())
if t<=k:print(t)
elif n>=t:print(k)
else:print((n//k+1)*k-t)