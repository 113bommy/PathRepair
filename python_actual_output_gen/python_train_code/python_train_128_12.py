a=int(input())
b=int(input())
if abs(b-a)%2==0:
    n=abs(b-a)/2
    m=abs(b-a)/2
    value=(n*(n+1))/2 + (m*(m+1))/2
    value=int(value)
    print (value)
if abs(b-a)%2!=0 and abs(b-a)!=1:
    n=(b-a+1)/2
    m=(b-a-1)/2
    value=(n*(n+1))/2 + (m*(m+1))/2
    value=int(value)
    print (value)
if abs(b-a)==1:
    print (1)
