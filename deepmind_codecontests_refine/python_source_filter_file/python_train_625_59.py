a,b,c=list(map(int,input().split()))
n=0
for i in range(a,b):
    n+=(c%i==0)
print(n)