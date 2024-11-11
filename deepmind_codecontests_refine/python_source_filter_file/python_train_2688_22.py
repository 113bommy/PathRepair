from fractions import*
a,b=map(int,input().split())
c=gcd(a,b)
d=a*b//gcd(a,b)
s=input()
t=input()
for i in range(c):
    if s[i*(a//c)] != t[i*(b//c)]:
        print(-1)
        exit
print(d)