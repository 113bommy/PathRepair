n,a,b=map(int,input().split())
count=0
for i in range(1,n+1):
    if(i>=a and n-i<=i):
        count+=1
print(count)
