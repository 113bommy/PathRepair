n,a,x,b,y=map(int,input().split())
if x>a:r1=[i for i in range(a,x+1)]
else:r1=[i for i in range(a,101)]+[i for i in range(1,x+1)]
if b>y:r2=[i for i in range(y,b+1)]
else:r2=[i for i in range(y,101)]+[i for i in range(1,b+1)]
flag=0
for x in range(min(len(r1),len(r2))):
    if r1[x]==r2[-1-x]:
        flag=1
        break
# print(r1)
# print(r2)
if flag==0:print("NO")
else:print("YES")