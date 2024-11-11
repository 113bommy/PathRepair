while 1:
 n=int(input())
 if n==0:break
 a=[int(input())for _ in[0]*n]
 for i in range(n-1):a[i]=max(a[i],a[i]+a[i-1])
 print(max(a))
