from math import factorial as f
n,m,t=map(int,input().split())
ans=0
for i in range(4,n+1):
    if m>=t-i and t-i>0:
        ans+=(f(n)/(f(i)*f(n-i)))*(f(m)/(f(t-i)*f(m-(t-i))))
print(ans)