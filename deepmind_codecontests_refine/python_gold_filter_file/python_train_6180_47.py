count=0
a=list(map(int,input().split()))
a.sort()
for j in range(3):
    if(a[j]!=a[j+1]):
        count=count+1
print(3-count)