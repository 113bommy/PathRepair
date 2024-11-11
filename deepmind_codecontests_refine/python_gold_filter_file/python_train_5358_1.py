n=int(input())
m=int(input())
a=[0]*(m+n+1)
a[len(a)-m-1]=m+n+1
for i in range(n):
    a[i]=i+1
for j in range(len(a)-m,m+n+1):
    a[j]=len(a)+n-j
print(*a,sep=" ")