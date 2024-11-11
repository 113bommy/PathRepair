a=input().split()
a[0]= int(a[0])
a[1]= int(a[1])
b = []
for i in range(a[0]):
    b.append(input().split())
    b[i][0]= int(b[i][0])-1
    b[i][1]= int(b[i][1])-1
c = [[n,0] for n in range(a[1])]
for i in range(a[0]):
    if b[i][1]+1>a[1]:
        print(i,c,b,a)
        c[a[1]][1] = 1
    else:
        for l in range(b[i][0],b[i][1]+1):
            c[l][1]=1

temp = []
tempnum = 0
for i in range(a[1]):
    if c[i][1] == 0:
        temp.append((i+1)%a[1])
        tempnum+=1
if tempnum == 0:
    print(tempnum)
else:
    print(tempnum)
    for i in range(len(temp)):
        print(temp[i], end = ' ')
