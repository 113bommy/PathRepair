a,b=map(int,input().split())
grid=[["."]*(a+2)]+[list("."+input()+".")for i in range(b)]+[["."]*(a+2)]
for s in range(1,1+a):
    for t in range(1,1+a):
        if grid[s][t]=="#" and all([grid[s+x][t+y]=="."for x,y in ([0,-1],[0,1],[1,0],[-1,0])]):
            print("No")
            #exit()
print("Yes")