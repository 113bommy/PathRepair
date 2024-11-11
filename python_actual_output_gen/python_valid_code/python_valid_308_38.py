n,m=[int(i) for i in input().split(" ")]
coord=[1]
sol=[]
count=0
for i in range(n):
    x,y=[int(i) for i in input().split(" ")]
    for j in range(x,y+1):
        coord.append(j)
for i in range(1,m+1):
    if i not in set(coord):
        sol.append(i)
        count+=1
print(count)
[print(i) for i in sol]