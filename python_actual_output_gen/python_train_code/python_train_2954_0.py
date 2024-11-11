n,k=map(int,input().split())
l=list(map(int,input().split()))
m=0
index=0
for i in range(n):
    c=0
    for j in range(n):
        if l[i]+(j-i)*k<0:
            break
        if l[i]+(j-i)*k==l[j]:
            c=c+1        
    if m<c:
        m=c
        index=i       
a=0
print(n-m)
for i in range(n):
    if l[i]!=l[index]-(index-i)*k:  
        if l[i]<l[index]-k*(index-i):  
            print("+",i+1,l[index]-(index-i)*k-l[i])
        else:
            print("-",i+1,l[i]-l[index]+k*(index-i)  )