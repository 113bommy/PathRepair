n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
for i in range(n):
    if a[i]<(n-k):
        c+=1
print(c//3)