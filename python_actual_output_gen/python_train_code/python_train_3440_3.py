n=int(input())
x=1
for i in range(1,n+1):
    x*=i

res=1

for i in range(2,n+1):
    cnt=1
    while x%i==0:
        x=x/i
        cnt+=1
    res*=cnt
    
print(res%(10**9+7))