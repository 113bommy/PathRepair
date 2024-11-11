n,k,x=map(int,input().split())
l=list(map(int,input().split()))
a=[0]*n
b=[0]*n
for i in range(1,n): a[i]=a[i-1]|l[i-1]
for i in range(1,n): b[n-i-1]=b[-i]|l[-i]
nom=0
for i in range(n):
    if l[nom]*(x**k)|a[i]|b[i]<l[i]*(x**k)|a[i]|b[i]: nom=i
l[nom]*=x**k
print(l[nom]|a[nom]|b[nom])