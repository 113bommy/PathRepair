n,k=map(int,input().split())
l=list(map(int,input().split()))
s=0
for i in range(len(l)):
    try:
        if k==0:
            break
        if i%2==1:
            if l[i]>l[i-1] and l[i]>l[i+1]:
                l[i]-=1
                s+=1
                if s==k:
                    break
    except:
        pass
print(*l)
    
