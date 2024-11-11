x=[]
n=4
for i in range(n):
    x.append(list(input()))
k=False
for i in range(1,n):
    for j in range(1,n):
        c=0
        if x[i][j]=="#":
            c+=1
        if x[i-1][j]=="#":
            c+=1
        if x[i][j-1]=="#":
            c+=1
        if x[i-1][j-1]=="#":
            c+=1
        if c>=3:
            k=True
            break
if k:
    print("YES")
else:
    print("NO")