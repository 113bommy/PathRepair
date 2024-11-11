n,m=map(int,input().split())
l=[int(i) for i in input().split()]
i=0 
sm=1 
cnt=0 
while i<n:
    sm+=l[i]
    if sm>m:
        cnt+=1 
        sm=l[i]
    i+=1 
print(cnt)