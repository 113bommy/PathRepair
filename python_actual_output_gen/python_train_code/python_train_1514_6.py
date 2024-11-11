n=int(input())
l=list(map(int,input().split()))
l.sort()
m=l[0]
c=0
k=0
for i in l[1:]:
    if(i>m):
        k+=1
        p=l[k]
        c+=1
print(c)