n,m=map(int,input().split())
acf,waf=[0]*n,[0]*n
ac,wa=0,0
for i in range(m):
    x,y=input().split()
    x=int(x)
    if y=='AC':
        if acf[x]==0:
            ac+=1
            wa+=waf[x-1]
            acf[x-1]+=1
    else:
        waf[x-1]+=1
print(ac,wa)
