f=[int(x) for x in input().split()]
f=f[1:]+[f[0]]
l=['A', 'B', 'C', 'D']
grid=[]
for x in l:
    for _ in range(7):
        grid.append(list(x*50))

for i,x in enumerate(f):
    p=1+i*7
    q=1
    h=0
    for _ in range(x):
        grid[p][q+h]=l[(i+1)%4]
        if q+h>=47:
            p+=1
            q=1
            h=1-h
        else:
            q+=2
print(len(grid), 50)
grid=["".join(x) for x in grid]            
print("\n".join(grid))
        