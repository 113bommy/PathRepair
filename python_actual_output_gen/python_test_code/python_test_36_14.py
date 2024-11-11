n=int(input())
c=0

if(n>=100):
    x=n//100
    n=n%100
    c=c+x
if(n>=20):
    x=n//20
    n=n%20
    c=c+x
if(n>10):
    x=n//10
    n=n%10
    c=c+x
if(n>=5):
    x=n//5
    n=n%5
    c=c+x
   
if(n>=1):
    c=c+n
print(c)