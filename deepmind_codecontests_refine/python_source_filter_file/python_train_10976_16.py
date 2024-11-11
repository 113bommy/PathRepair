n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in range(n):
    if (5-l[i]>=0):
        c=c+1
print(c//3)