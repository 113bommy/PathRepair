from fractions import *
n=int(input());
a=list(map(int,input().split()));
sorted(a);
now=a[0];
ans=0;
for i in range(1,n):
    ans+=i*a[i]-now;
    now=now+a[i];
ans=ans*2+now;
s=Fraction(ans,n);
print(s.numerator,s.denominator);