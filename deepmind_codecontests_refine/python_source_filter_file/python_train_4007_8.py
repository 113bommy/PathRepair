def createl(m):
    l=[]
    for i in range(0,m):
        l.append(0)
    return l
           
line = input()
x = line.split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])
l = []
lf=[]
kk=0

for j in range (0,n):
    l.append(createl(m))
for i in range(0,k):
    line= input()
    x = line.split(' ')
    a = int(x[0])
    b = int(x[1])
    a=a-1
    b=b-1
    l[a][b] = 'x'
    if (a>0) and (b>0):
        if (l[a-1][b]=='x') and (l[a-1][b-1]=='x') and (l[a][b-1]=='x'):
            print(i+1)
            kk+=1
            break
    if (a<n-1) and (b>0):
        if (l[a+1][b]=='x') and (l[a+1][b-1]=='x') and (l[a][b-1]=='x'):
            print(i+1)
            kk+=1
            break
    if (a<n-1) and (b<m-1):    
        if (l[a+1][b]=='x') and (l[a+1][b+1]=='x') and (l[a][b+1]=='x'):
            print(i+1)
            kk+=1
            break
    if (a>0) and (b<m-1):
        if (l[a-1][b]=='x') and (l[a-1][b+1]=='x') and (l[a][b+1]=='x'):
            print(i+1)
            kk+=1
            break
    for i in range(0,n):
        print(l[i])
if kk==0:
    print(0)

    
