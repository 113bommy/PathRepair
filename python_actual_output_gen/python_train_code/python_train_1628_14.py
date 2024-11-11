a,b,c=map(int,input().split())
d=0
e=0
f=0
if a+b<=c:
    d=(c-(a+b))+1
if b+c<=a:
    e=(a-(b+c))+1
if c+a<=b:
    f=(b-(a+c))+1
print(d,e,f)
5
