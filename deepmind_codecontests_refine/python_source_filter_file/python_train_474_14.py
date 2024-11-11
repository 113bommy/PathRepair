
a=list(map(int,input().split()))
n=a[0]
k=a[1]
a=list(map(int,input().split()))
b=[0]*n
s=[0]*2
m=0
i=0
while m!=n:
   b=a[m]//k
   if (a[m]%k)>0:
       b=int(a[m]/k)+1
   i+=b
   m+=1
if (i%2)>0:
    print(int(i/2)+1)
else:
    print(i/2)
        
