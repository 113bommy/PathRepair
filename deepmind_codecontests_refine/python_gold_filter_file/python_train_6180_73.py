a=list(map(int,input().split()))
a.sort()
sum=0
for i in range(len(a)-1):
    if a[i]==a[i+1]:
        sum=sum+1
print(sum)            
