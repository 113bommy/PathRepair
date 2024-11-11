n=int(input())
s=input()
d={'R':0,'G':0,'B':0}
for i in s:
  d[i]+=1
ans=1
for i in d:
  ans*=d[i]
for k in range(n//2):
  for i in range(n-2*k):
    if len(set([s[i],s[i+k],s[i+2*k]]))==3:ans-=1
print(ans)