n,k=map(int,input().split())
li=list(map(int,input().split()))
max=0
box=0
type=0
for i in range(k):
    temp=n-n%li[i]
    if temp>max:
        type=i+1
        box=temp//li[i]
        max=temp
print(type,box)
