n=int(input())
a=list(map(int,input().split()))
ans=0
p=10**9 + 7 
l=[0]*60
for i in range(60):
    for j in a:
        l[i]+=(j>>i)&1
    ans=(ans + (2**i) * l[i] * (n-l[i]))%p
print(ans) 