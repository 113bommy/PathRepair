a,b,c=list(map(int,input().split()))
n=0
for i in range(a,b+1):
    n+=(c%i==0)
print(n)