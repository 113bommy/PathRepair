n=int(input())
l=list(map(int,input().split()))
a=[]
b=[]
j=m=k=0
for i in l:
    a.append(abs(i-1))
    b.append(abs(i+1))
for i in range(len(l)):
    m+=min(a[i],b[i])
    if(b[i]<a[i]):
       j+=1
    if(b[i]<=a[i]):
       k+=1
if(j%2==1 and k%2==1):
    print(m+2)
else:
    print(m)
