
n,t=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
l=[[l2[i],l1[i]] for i in range(n)]
l.sort()
s1=sum([l[i][0]*l[i][1] for i in range(n)])
s2=sum(l1)
s=s1/s2
f=n-1
d=0

if s<t:
    while s<t and d<n:
        s2=s2-l[d][1]
        s1=s1-l[d][0]*l[d][1]
        if s!=0:
            s2=s1/s2
        if s>t:
            s2+=(s2*t-s1)/(l[d][0]-t)
            break
        elif s==t:
            break
        else:
            d+=1
    
elif s>t:
    while s>t and f>=0:
        s2=s2-l[f][1]
        s1=s1-l[f][0]*l[f][1]
        if s2!=0:
            s=s1/s2
        if s<t:
            s2+=(t*s2-s1)/(l[f][0]-t)
            break
        elif s==t:
            break
        else:
            f-=1
print(s2)
        
    
