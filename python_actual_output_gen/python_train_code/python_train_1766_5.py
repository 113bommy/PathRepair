x=int(input())
p=list(map(int,input().split()))
y=0
for i in range(x-1):
    if p[i]==0 and p[i+1]==1 and p[i-1]==1:
        y+=1
        p[i+1]=0
print(y)