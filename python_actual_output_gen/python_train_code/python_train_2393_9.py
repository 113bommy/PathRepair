n,m=(int(i) for i in input().split())
k1=max(n,m)
k2=min(n,m)
if(k1<=1):
    print(0)
elif(k2<=2*k1):
    print(k2)
else:
    print((n+m)//3)