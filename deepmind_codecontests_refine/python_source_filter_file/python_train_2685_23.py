n,m=map(int,input().split())
a = [int(x)//2 for x in input().split()]
import fractions
lmc=a[0]
for i in range(1,n):
    lmc=lmc*a[i]//fractions.gcd(lmc,a[i])
    if lmc>m:
        print("0")
        exit()
for i in range(n):
   if (lmc//a[i])%2==0:
      print("0")
      exit()
if (m//lmc)%2==0:
    print((m//lmc)%2)
else:
    print(((m//lmc)+1)%2)