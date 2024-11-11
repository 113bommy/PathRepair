n=int(input())
b=list(map(int,input().split()))
s=b[0]
for i in range(1,n-1):
    s+=min(b[i],b[i-1])
print(s+b[n-2])