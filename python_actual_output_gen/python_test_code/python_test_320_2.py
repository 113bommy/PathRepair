n=int(input())
m=list(map(int,input().split()))
h=list(map(int,input().split()))
a=0
for i in range(N):
  if h[i]<m[i]:
    a+=h[i]
  else:
    a+=m[i]
    r=h[i]-m[i]
    s=min(m[i+1],r)
    a+=s
    m[i+1]-=s
print(a)