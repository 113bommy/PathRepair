n,r=map(int,input().split())
k,m=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
count=0
for i in range (k):
    if(l2[r-m]>l1[i]):
        count+=1
if(count==k):
    print("YES")
else:
    print("NO")