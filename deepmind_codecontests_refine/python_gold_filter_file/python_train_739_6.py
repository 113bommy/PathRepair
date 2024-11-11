n=int(input())
l2=[0]
for i in range(0,n):
    x=int(input())
    y=len(l2)
    for i in range (0,y):
        l2.append(l2[i]-x)
        l2.append(l2[i]+x)
    l2=l2[y:]
flag=0
for item in l2:
    if item%360==0:
        flag=1
        break
if flag==1:
    print("YES")
else :
    print("NO")

    