
n,k,t=map(int,input().split())
if t<k:
    print(t)
elif t>k:
    print(k)
else:
    print(k+n-t)
