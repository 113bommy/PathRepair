a,b=map(int,input().split())
c=list(map(int,input().split()))
d=list(map(int,input().split()))
k=0
k1=0
for i in c:
    if i%2==0:
        k+=1
    else:
        k1+=1
l=0
l1=0
for j in d:
    if j%2==0:
        l+=0
    else:
        l1+=1
print(min(k,l1)+min(k1,l))