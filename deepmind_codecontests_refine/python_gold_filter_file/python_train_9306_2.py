x,y=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in range(len(l)):
    for j in range(i+1,len(l)):
        if abs(l[i]-l[j])<=y:
           c+=2
print(c)