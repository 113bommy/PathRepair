''' problem d'''
n,a,b,k=[int(x) for x in input().split()]
h=list(map(int,input().split()))
ans = C =0
for i in range(n):
    h[i]=h[i]%(a+b)
    if h[i]==0:
        h[i]=a+b
    h[i]-=a
h.sort()

for val in h:
    if val<=0:
        ans+=1
    else:
        c=(val//a)
        if val%a!=0:
            c+=1
        if(C+c <= k):
            ans+=1
            C+=c
        else:
            break
            
print(ans)
    
    
