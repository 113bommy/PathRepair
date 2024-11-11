
count=0
n,m=map(int,input().split())
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
odd1=0
even1=0
odd2=0
even2=0
for i in arr1:
    if i%2==0:
        even1+=1
    else:
        odd1+=1
for i in arr2:
    if i%2==0:
        even2+=1
    else:
        odd2+=1
print(min(even1,odd2)+min(even2,odd1))
