i=0
a=list(map(int,input().split()))
for x in range(a[0],a[1]+1):
    if(a[2]%x==0):
        i+=1
print(i)