I=lambda:map(int,input().split())
n,m=I()
a,b=sorted(I(),reverse=1),sorted(I())
s=sum(b)
for i in range(1,n):s+=a[i]*m
if a[0]>b[-1]:s=-1
elif a[0]!=b[0]:s+=a[0]-a[1]
print(s)