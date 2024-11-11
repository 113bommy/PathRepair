t=int(input())
count=0
list1=list(map(int,input().split()))
for j in list1:
    if j==1:
        count=count+1
if count >=1:
    print("NO")
else:
    print("YES")