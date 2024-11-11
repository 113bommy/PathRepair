n,m=map(int,input().split())
countern=[0]*n
counterm=[0]*m

for i in range(n):
    x=input()
    for j in range(m):
        if x[j]=='S':
            countern[i]=1
            counterm[j]=1

sumn=0
for i in range(n):
    sumn+=countern[i]
summ=0
for i in range(m):
    summ+=counterm[i]
print(n*m-sumn*sumn)