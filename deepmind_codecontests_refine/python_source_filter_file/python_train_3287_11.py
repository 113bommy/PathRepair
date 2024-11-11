from math import *
n,m,k=map(int,input().split())
r,l=0,0

r=n-k
l=k-1
s=max(l,r)+1
if l>r:
    S=((1+l)*(l)//2)+((s-1+s-r)*r//2)
else:
    S=((1+r)*(r)//2)+((s-1+s-l)*l//2)
S+=max(l,r)+1
L,R=max(l,r),min(l,r)
s1=s
s2=1
S1=n
S2=S
if S1==m:
    s=1
elif S>m:
    while (S1!=S2) or (S2>m):
        S1=S2
        s=(s1+s2)//2   
        if R<s:
            S2=((s+1)*s//2)+(L-s)+((s-1+s-R)*R//2)
        else:
            S2=((s+1)*s//2)+(L-s+1)+((s)*(s-1)//2)+(R-s+1)
        
        if S1==S2 and S2<=m:
            break
        if S2>m:
            s1=s
        elif S2<m:
            s2=s
        else:
            break
    
     
else:
    s+=(m-S)//n
print(s)
