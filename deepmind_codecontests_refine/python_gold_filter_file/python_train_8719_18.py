g={'purple':'Power','green':'Time','orange':'Soul',"blue":"Space","red":"Reality",'yellow':"Mind"}
n=int(input().strip())
print(6-n)
c=[]
for _ in range(n):
    c.append(input().strip())
gems=[]
for i in g:
    if i not in c:
        gems.append(g[i])
for k in gems:
    print(k)