n,k=map(int,input().split())
a=list(map(int,input().split()))
l=[0]
for i in range(1,n):
  b=a[i]
  l.append(min(l[j]+abs(b-a[j])for j in range(max(0,i-k),i)))
print(l[-1])