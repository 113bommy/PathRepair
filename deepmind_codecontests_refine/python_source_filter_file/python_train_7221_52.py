a=[]
for i in range(0, 5):
	a.append([int(x) for x in input().split()])

for i in range(0, 5):
    for j in range(0, 5):
        if a[i][j]==1:
            print(0 if i==2 and j==2 else abs(2-(i+j)))
            break
    
