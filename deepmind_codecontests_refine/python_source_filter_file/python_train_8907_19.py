from bisect import bisect_left as bl
import math
def factors(n):
    l=[]
    for i in range(1,int(n**0.5)+1):
        if n%i==0:
            l.append(i)
            if i!=n//i:
                l.append(n//i)
    return(sorted(l))
a,b=map(int,input().split())
g=math.gcd(a,b)
l=factors(g)

#print(g)
for i in range(int(input())):
    l1,h=map(int,input().split())
    if l1<=g<=h:
        ans=g
    elif h<g:
        x=bl(l,h)
        if x<len(l) and l[x]==h:
            ans=h
        elif l[x-1]>l1:
            ans=l[x-1]
        else:
            ans=-1
    else:
        ans=-1
    print(ans)