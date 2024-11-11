k,n=map(int,input().split())
a=list(map(int,input().split()))+[k]
d=abs(a[0]+(k-a[-1]))
for i in range(n):
  d=max(d,abs(a[i]-a[i+1]))
print(k-d)