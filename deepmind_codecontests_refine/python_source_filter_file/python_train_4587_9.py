while 1:
 n,x=map(int,input().split())
 if n+x==0:break
 print(len([1 for i in range(1,n-2)for j in range(i+1,n)if j<x-i-j<=n]))