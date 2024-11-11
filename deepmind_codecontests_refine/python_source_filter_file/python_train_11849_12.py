n=int(input())
s=input()
m=list(set(s))
ans=1
for i in m:
    ans*=s.count(i)-1
print((ans-1)%(10**9+7))