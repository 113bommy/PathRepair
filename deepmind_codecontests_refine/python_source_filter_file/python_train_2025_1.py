n=int(input())
sl=list(map(int,input().split()))
p=max(sl)
q=min(sl)
a=-1
k=0
p=10000000000
for i in range(1,n):
    if sl[i]>=sl[i-1]:
        if a<0:
            p=min(p,sl[i-1])
        if a>=0:
            k=max(k,sl[i])
        continue
    else:
        if (p==sl[i-1] and q==sl[i]) :
            a+=1
            ans=n-i 
        else:
            a=-2
            break
if k>p:
    a=0
if a==-1:
    print("0")
elif a==-2 or a>0:
    print("-1")
elif a==0:
    print(ans)