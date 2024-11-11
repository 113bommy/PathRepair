n,k=input().split()
n=int(n)
k=int(k)

a=input().split()
a=list(map(int,a))

typ=1
num=0
maxi=0
hms=0
for i in range(k):
    hms=int(n/a[i])*a[i]
    if(hms>maxi):
        typ=i+1
        num=hms/a[i]
        maxi=hms
print(typ,int(num))
    
