n=int(input())
l=list(map(int,input().split()))
l1=[0]
l1=l1*n
for i in range(n-2,0,-1):
    if(l[i]>=l[i+1]):
        l1[i]=l1[i+1]+1
print(max(l1))