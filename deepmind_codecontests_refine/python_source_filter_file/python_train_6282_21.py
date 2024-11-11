I=lambda:map(int,input().split())
n,m=I();a=list(I());b=list(I());import math
if n==m:
 q=math.gcd(a[0],b[0])
 a[0]//=q;b[0]//=q
 print(str(abs(a[0])if a[0]*b[0]>0 else -a[0])+"/"+str(abs(b[0])))
elif n<m:print('0/1')
else:
 if a[0]*b[0]>0 :print("Infinity")
 else:print("-Infinity")