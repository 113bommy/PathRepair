n,m=map(int,input().split())
t=[0]*110
#Sign the teleports' limit
for a in range(n):
    x,y=map(int,input().split())
    t[x:y+1]=[1]*(y-x)
#check whether the all axis is reached
for i in range(m+1):
    if t[i]==0:
        print("No")
        exit(0)
print("Yes")