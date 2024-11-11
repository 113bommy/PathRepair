a = [""]*11
for i in range(11):
    a[i]=list(input())
x,y = map(int, input().split())
k=0
x1=(x-1)%3
y1=(y-1)%3
if y1==0:
    y2=2
if y1==1:
    y2=6
    y1=4
if y1==2:
    y2=10
    y1=8
if x1==0:
    x2=2
if x1==1:
    x2=6
    x1=4
if x1==2:
    x1=8
    x2=10
for i in range(x1,x2+1):
    for j in range(y1,y2+1):
        if a[i][j]==".":
            a[i][j]="!"
            k=1
if k==0:
    for i in range(11):
        for j in range(11):
            if i!=3 and i!=7 and j!=3 and j!=7:
                if a[i][j]==".":
                    a[i][j]="!"
for row in a:
    print(' '.join([str(elem) for elem in row]))
print()
#�����