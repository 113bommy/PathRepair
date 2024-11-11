n,k=map(int,input().split())
l1=list(map(int,input().split()))
l2=[0]*k
for item in l1:
    l2[(item)%k]+=1
t=0
for i in range(0,k//2+1):
    if i==0:
        t+=2*(l2[i]//2)
    else :
        if i!=k-i:
            t+=2*(min(l2[i],l2[k-i]))
        else :
            if l2[i]>1:
                t+=l2[i]
print(t)