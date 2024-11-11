d=[0,0,0,0]
for i in range(3):
    a,b=map(int,input().split())
    d[a-1]+=1
    d[b-1]+=1

if d[0] <= 2 and d[1] <= 2 and d[2] <= 2 and d[3] <= 2:
    print("Yes")
else:
    print("No")