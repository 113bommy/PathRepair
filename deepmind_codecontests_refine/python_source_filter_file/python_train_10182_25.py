n=int(input())
a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
s=[0]*(n+1)
for i in range(a,n+1):
  s[i]=max(s[i],s[i-a]+d-a)
for i in range(b,n+1):
  s[i]=max(s[i],s[i-b]+e-b)
for i in range(c,n+1):
  s[i]=max(s[i],s[i-b]+f-c)
n+=s[-1]
s=[0]*(n+1)
for i in range(d,n+1):
  s[i]=max(s[i],s[i-d]+a-d)
for i in range(e,n+1):
  s[i]=max(s[i],s[i-e]+b-e)
for i in range(f,n+1):
  s[i]=max(s[i],s[i-f]+c-f)
print(n+s[-1])