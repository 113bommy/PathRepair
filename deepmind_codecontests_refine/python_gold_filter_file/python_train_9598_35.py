n,a,b=map(int,input().split())
count=0
for i in range(1,n+1):
    if a+1<=i and n-b<=i:
        count+=1
print(count)
