n,t=map(int,input().split())
sum=0
a=list(map(int,input().split()))
for i in range(n):
    
    sum+=(86400-a[i])
    if sum==t:
        break
print(i+1)

