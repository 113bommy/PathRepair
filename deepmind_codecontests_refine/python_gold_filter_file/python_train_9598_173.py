n,a,b=map(int,input().split())

n=n-1
count=0
for x in range(101):
    if (n-a)<=b and (n-a)>=0:
        count+=1
    a+=1
print(count)        
