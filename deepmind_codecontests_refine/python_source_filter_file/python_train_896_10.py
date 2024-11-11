n,m=map(int,input().split())
t=[0]*101
#Sign the teleports' limit
for i in range(n):
    x,y=map(int,input().split())
    t[x+1:y+1]=[1]*(y-x)
#check whether the all axis is reached
for i in range(m):
    if t[i]==0:
        print("No")
        exit(0)
print("Yes")