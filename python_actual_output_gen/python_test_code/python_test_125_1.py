md,n=998244353,int(input())
arr=list(map(int,input().split()))
sigma=(sum(arr[n:])-sum(arr[:n]))%md
up,dn=1,1
for i in range(1,n+1):
    up=(up*(n+i))%md
    dn=(dn*i)%md
print((((sigma*up)%md)*pow(dn,md-2,md))%md)