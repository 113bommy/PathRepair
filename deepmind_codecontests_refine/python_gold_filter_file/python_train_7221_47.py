l=[[],[],[],[],[]]
x=y=0
for i in range(5):
    l[i]=[int(x) for x in input().split()]
for i in range(5):
    if 1 in l[i]:
        x=i+1
        for j in range(5):
            if l[i][j]==1:
                y=j+1
                break
    else:
        continue
print(abs(x-3)+abs(y-3))
