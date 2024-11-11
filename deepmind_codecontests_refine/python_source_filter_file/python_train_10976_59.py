n,k=map(int, input().split())
y=list(map(int, input().split()))
count=0
k=0
for i in y:
    if i<=5-k:
        k+=1
    if k==3:
        count+=1
        k=0
print(count)