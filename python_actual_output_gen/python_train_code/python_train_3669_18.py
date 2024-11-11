n,k,t=map(int,input().split())

if t<=k:
    print(t)

elif t>n:
    print(max(5-(t-n),0))
    
else:
    print(k)