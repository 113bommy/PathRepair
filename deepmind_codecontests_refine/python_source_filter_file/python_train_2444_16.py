import math
import sys

n,m=map(int,input().split())

field=[list("0"*(m+2))]
count=[[0]*(m+2)]

for i in range(n):
    s=["0"]+list(str(input()))+["0"]
    field.append(s)
    count.append([0]*(m+2))

field.append(list("0"*(m+2)))
count.append([0]*(m+2))

flag=False
vector=[[-1,0],[1,0],[0,-1],[0,1]]
for i in range(1,n+1):
    for j in range(1,m+1):

        if count[i][j]==0:
            count[i][j]=1
            q=[[i,j]]
            color=field[i][j]

            while q!=[]:
                r=0;x=q[0][1];y=q[0][0]
                for direct in range(4):
                    new_x=x+vector[direct][0]
                    new_y=y+vector[direct][1]
                    if field[new_y][new_x]==color:
                        if count[new_y][new_x]==0:
                            count[new_y][new_x]=1
                            q.append([new_y,new_x])
                        else:
                            r+=1
                if r>=2:
                    flag=True

                q.pop(0)

if flag:
    print("YES")
else:
    print("NO")

