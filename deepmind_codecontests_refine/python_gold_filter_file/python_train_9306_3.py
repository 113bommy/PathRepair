x,y=[ int(a) for a in input().split()]
l=[int(b) for b in input().split()]
count=0
k=len(l)-1
for i in range(len(l)-1):
    for j in range(i+1,len(l)):
        if abs(l[j]-l[i])<=y:
            count=count+1
print(count*2)