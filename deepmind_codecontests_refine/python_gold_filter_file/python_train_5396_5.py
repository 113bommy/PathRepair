h,w=map(int,input().split())
a=[]
for i in range(h):a.append(list(input()))
white=[flatten for inner in a for flatten in inner].count(".")
turn=1
a[-1][-1]=1
while turn in [flatten for inner in a for flatten in inner]:
    for i in range(h):
        for j in range(w):
            if a[i][j]==turn:
                if i>0 and a[i-1][j]==".":a[i-1][j]=turn+1
                if i<h-1 and a[i+1][j]==".":a[i+1][j]=turn+1
                if j>0 and a[i][j-1]==".":a[i][j-1]=turn+1
                if j<w-1 and a[i][j+1]==".":a[i][j+1]=turn+1
    turn+=1
    if a[0][0]!=".":break
print(-1 if a[0][0]=="." else white-a[0][0])