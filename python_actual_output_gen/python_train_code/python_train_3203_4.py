x,y=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in range(len(l)):
    for j in range(len(l)):
        if abs(l[i]-l[j])<=y:
            c+=1
print(c)