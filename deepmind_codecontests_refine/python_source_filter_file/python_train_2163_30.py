n=int(input())
l=list(map(int,input().split()))
s=sum(l)
s=s**2
for i in range(n):
  s=s-l[i]**2
s=s/2
print(int(s%(7+10**9)))  