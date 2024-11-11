n,t=map(int,input().split())
l=list(map(int,input().split()))
m=list(map(int,input().split()))
count=0
k=0
for i in range(len(m)):
    j=k
    f=0
    while(j<n):
        if m[i]>l[j]:
            k=j+1
            count+=1
            f=1
            break
        j+=1
    if f==0:
        break
print(count)
