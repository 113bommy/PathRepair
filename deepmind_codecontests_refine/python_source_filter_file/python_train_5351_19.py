def string_to_list(a):
    y=[]
    for i in range(len(a)):
        y.append(a[i])
    return y
a= list(map(int, input().split()))
r,c,b=a[0],a[1],[]
for i in range(r):
    d=input()
    d1=string_to_list(d)
    b.append(d1)
for i in range(c):
    es=0
    for j in range(r):
        if b[j][i]=='S':
            es+=1
            break
    if es==0:
        for k in range(r):
            b[k][i]='E'
for i in range(r):
    es1=0
    for j in range(c):
        if b[i][j]=='S':
            es1+=1
            break
    if es1==0:
        for k in range(r):
            b[i][k]='E'
count=0
for i in range(r):
    for j in range(c):
        if b[i][j]=='E':
            count+=1
print(count)