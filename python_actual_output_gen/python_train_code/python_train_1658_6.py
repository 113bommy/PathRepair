
N,A,B = list(map(int,input().split()))

item=[]
for i in range(N):
    a,b,c = list(map(int,input().split()))
    item.append([a,b,c])

D = [[[10**27 for i in range(401)] for j in range(401)] for k in range(N+1)]
D[0][0][0] = 0
for i in range(N):
    for j in range(401):
        for k in range(401):
            if D[i][j][k]<10**26:
                D[i+1][j][k]=min(D[i+1][j][k],D[i][j][k])
                D[i+1][j+item[i][0]][k+item[i][1]] = min(D[i+1][j+item[i][0]][k+item[i][1]],D[i][j][k]+item[i][2])

i=1
min_cost=10**27
while A*i<=400 and B*i<=400:
    min_cost = min(D[A*i][B*i],min_cost)
    i+=1
if min_cost==10**27:
	print(-1)
else:
	print(min_cost)