n,k=map(int,input().split())
ar=[True for i in range(n+1)]
prime=2
while(prime*prime<=n):
    if ar[prime]==True:
        for i in range(prime*prime,n+1,prime):
            ar[i]=False
    prime+=1
ar1=[]    
for i in range(2,n+1):
    if ar[i]==True:
        ar1.append(i)         
for i in range(len(ar1)-1):
    if ar1[i]+ar1[i+1]+1 in ar1:
        k-=1
if k==0 or k<0:
    print("YES")
else:
    print("NO")