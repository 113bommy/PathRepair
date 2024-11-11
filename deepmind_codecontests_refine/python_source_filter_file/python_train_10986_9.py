n=int(input())
a=list(map(int,input().split()))
b1=[1]*(n)
b2=[0]*(n)
i=1
while i<(len(a)):
    if a[i]>=a[i-1]:
        b1[i]=b1[i]+b1[i-1]
    j=i
    while(j<(len(a))):
        if j<len(a)-1 and a[j]>=a[j+1] and a[j]<=a[i]:
            j+=1
            flag=1
            b2[i]+=1
        else:
            break
    i+=1
max1=0
for i in range(n):
    if max1<b1[i]+b2[i]:
        max1=b1[i]+b2[i]
print(max1)
        
        
    