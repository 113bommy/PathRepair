n,m=map(int,input().split())
a=input()
b=input()
if n>m:b='0'*(n-m)+b
elif m>n:a='0'*(m-n)+a
s=0
c=0
for i in range(m):
    if b[i]=='1':c+=1
    if a[i]=='1':
        s=(s+c*pow(2,max(n,m)-i-1,998244353))%998244353
print(s)