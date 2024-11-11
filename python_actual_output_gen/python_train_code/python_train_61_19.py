I=lambda:list(map(int,input().split()))
n,k=I()
i=0
while i<=k:k-=i;i+=1
print(I()[k-1])