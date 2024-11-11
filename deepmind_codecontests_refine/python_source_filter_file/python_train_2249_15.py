n,m=map(int,input().split())
x=n 
a=[]
b=[]
c=[]
co=0
while x:
    x-=1 
    a.append (input())
for i in range (n):
    for j in range (m):
        if (a[i][j]=='B'):
            b.append (i)
            c.append (j)
            co+=1 
if (n==1 or m==1):
    if (n==1 ):
        r=a[0]
    else :
        r=a
    if (r.count('B')>1):
        print (-1)
    elif (r.count('B')==1):
        print (0)
    else :
        print (1)
    
elif (co==0):
    print (1)
else :
    l1=(max(b)-min(b))+1
    l2=(max(c)-min(c))+1
    if (l1==n and l2 == m and n==m):
        print (l1*l1 - len(b))
    elif (l1==n and l2==m and n!=m):
        print (-1)
    elif (l1>l2):
        if (l1<=n):
            print (l1*l1 -len(b))
        else :
            print (-1)
    else :
        if (l2<=m):
            print (l2*l2 - len(b))
        else :
            print (-1)
