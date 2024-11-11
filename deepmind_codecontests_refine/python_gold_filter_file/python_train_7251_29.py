n,s=map(int,input().split())
s+=1
k=[]
for i in range(n):
    a,b=map(int,input().split())
    k+=[a*60+b]
if k[0]>=s:
    print("0","0")
else:
    for i in range(1,n):
        if k[i]-k[i-1]>=2*s:
            print((k[i-1]+s)//60,(k[i-1]+s)%60)
            exit()
    print((k[n-1]+s)//60,(k[n-1]+s)%60)