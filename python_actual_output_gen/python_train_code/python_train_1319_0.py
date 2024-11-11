r,c=map(int,input().split())
graph=[]
for i in range(r):
    graph.append(input().rstrip())
f=0
for i in range(r):
    for j in range(c):
        if graph[i][j] is 'S':
            if i>0:
               if graph[i-1][j] is 'W':
                   f=1
                   break
            if i<r-1:
                if graph[i+1][j] is 'W':
                   f=1
                   break
            if j>0:
                if graph[i][j-1] is 'W':
                   f=1
                   break
            if j<c-1:
                if graph[i][j+1] is 'W':
                   f=1
                   break
if f==0:
    print("yes")
    for i in range(r):
        for j in range(r):
            if graph[i][j] is '.':
                print("D",end="")
            else:
                print(graph[i][j],end="")
        print("")
else:
    print("no")