l=list(map(int,input().split()))
count=0
for i in range(0,(len(l)-1)):
    if(l[i] == l[i+1]):
        count=count+1
print(count)