n,k=map(int,input().split())
y=list(map(int,input().split()))
y.sort()
i=0
for j in range(2,n,2):
    if 5-y[j]>=k:
        i+=1
print(i)
