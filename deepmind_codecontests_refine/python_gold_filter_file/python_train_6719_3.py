n,a=map(int,input().split())
l=list(map(int,input().split()))
count=0
for i in range(1,n+1):
    if(l[i-1]==1):
        d=i-a
        j=a-d
        if j<1 or j>n or l[i-1]==l[j-1]:
            count+=1
print(count)
