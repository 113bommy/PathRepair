d,k,a,b,t=map(int,input().split())
if d<=k:
    print(a*d)
elif t+ a*k>b*k:
    print(a*k + (d-k)*b)
else:
    print(a*k*d//k + (d//k -1)*t + min((d%k)*b,t+(d%k)*a))