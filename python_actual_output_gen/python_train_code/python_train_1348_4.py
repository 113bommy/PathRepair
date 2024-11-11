[n,m,k]=[int(i) for i in input().split()]
isDone=False
for i in range(0,k):
    [x,y]=[int(i) for i in input().split()]
    if x<5 or x>n-5 or y<5 or y>m-5:
        isDone=True
if isDone:
    print("YES")
else:
    print("NO")