n=int(input())
t=True
while(t):
    n=n+1
    a=n%10;
    b=(int(n/10))%10;
    c=(int(n/100))%10;
    d=(int(n/1000))%10;
    if (a!=b) and (a!=c) and (a!=d) and (b!=c) and (b!=d) and(c!=d):
        t=False
    