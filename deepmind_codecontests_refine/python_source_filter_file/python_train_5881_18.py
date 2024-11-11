d=int(input())
o=int(input())
f=int(input())
i=d
c=0
while i>=1:
    a=o%10
    b=f%10
    M=max(a,b)
    m=min(a,b)
    diff=M-m
    c=c+min(diff,10-diff)
    o/=10
    f/=10
    i-=1
print(c)    
    