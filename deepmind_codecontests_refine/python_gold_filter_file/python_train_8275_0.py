from math import *
a,v=list(map(int,input().split()))
l,d,w=list(map(int,input().split()))
if v>w:
    s1=w**2/2/a
    if d<=s1:
        s=min(v**2/2/a,l)
        t=sqrt(2*s/a)+(l-s)/v
    else:
        t=sqrt(2*s1/a)
        s2=min((d-s1)/2,(v**2-w**2)/(2*a))
        if s2==(d-s1)/2:
            t+=2*(sqrt(2*(s1+s2)/a)-sqrt(2*s1/a))
        else:
            t+=2*(v-w)/a+(d-s1-2*s2)/v
        s3=min((v**2-w**2)/2/a,l-d)
        t+=sqrt(2*(s3+s1)/a)-sqrt(2*s1/a)+(l-d-s3)/v
else:
    s=min(v**2/2/a,l)
    t=sqrt(2*s/a)+(l-s)/v
print(t)