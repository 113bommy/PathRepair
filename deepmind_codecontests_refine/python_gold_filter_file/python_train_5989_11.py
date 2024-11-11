n=int(input())
matrix=[]
sum=0
l=[]
lr=[]
lc=[]
for i in range(n):
    a=[]
    a.append(input())
    matrix.append(a)
for i in range(n):
    for j in range(n):
        if matrix[i][0][j]=='C':
            l.append((i,j))
for i in l:
    lr.append(i[0])
    lc.append(i[1])
for i in set(lc):
    if lc.count(i)>1:
        a=lc.count(i)
        sum+=(a)*(a-1)//2
for i in set(lr):
    if lr.count(i)>1:
        b=lr.count(i)
        sum+=(b)*(b-1)//2
print(sum)
