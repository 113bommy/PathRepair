d=int(input())
m=int(input())
a=list(map(int,input().split()))[:m]
count=0
for i in range(1,len(a)):
    count+=d-a[i]
print(count)
    
