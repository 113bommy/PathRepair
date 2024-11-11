a=[]
for i in range(3):
    lst=list(map(int,input().split()[:3]))
    a.append(lst)
a[1][1]=(a[0][1]+a[0][2]-a[1][0]-a[1][2]+a[2][0]+a[2][1]) // 2;

a[0][0]=a[1][0]+a[1][1]+a[1][2]-a[0][1]-a[0][2];
a[2][2]=a[1][0]+a[1][1]+a[1][2]-a[0][2]-a[1][2];

for i in range(3):
    for j in range(3):
        print(a[i][j],end=" ")
    print()