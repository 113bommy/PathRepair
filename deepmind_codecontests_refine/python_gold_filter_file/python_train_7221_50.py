l=[]
for _ in range(5):
    x=[]
    x=list(map(int,input().split()))
    l.append(x)
for i in range(5):
    for j in range(5):
        if l[i][j]==1:
            r=i+1
            c=j+1
            break
print(abs(r-3)+abs(3-c))
