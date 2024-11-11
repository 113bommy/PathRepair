n=int(input())
h=[10**6]+list(map(int,input().split()))
c=[0]*(n+1)
for i in range(2,n+1):
  a=c[i-1]+abs(h[i]-h[i-1])
  b=c[i-2]+abs(h[i]-h[i-2])
  c[i]=min(a,b)
print(c[n]