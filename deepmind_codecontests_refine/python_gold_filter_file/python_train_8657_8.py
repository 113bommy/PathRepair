from collections import Counter
n=int(input())
l=list(map(int,input().rstrip().split()))
f=0
if(len(l)<=3):
    print(1)
    exit()

z = {i+1:l[i] for i in range(n)}
so = sorted(z.items(),key = lambda x:(x[1],x[0]))
d = [so[i+1][1]-so[i][1] for i in range(n-1)]
c = set(d)
if(len(c)==1):
    print(so[0][0])
    exit()
if(len(c)>3):
    print(-1)  
    exit()
j = -1
if(len(set(d[1:]))==1 and so[2][1]-so[1][1] != so[1][1]-so[0][1]):
    j = so[0][0]
    f = 1
if(f==0):
    if(len(set(d[2:]))==1 and so[2][1]-so[0][1] == so[3][1]-so[2][1]):
        j = so[1][0]
        f = 1
D = so[1][1] - so[0][1]
if(f==0):
    for i in range(1,n-2):
        if(so[i+1][1]-so[i][1]!=D and so[i+2][1]-so[i][1]==D):
            j = so[i+1][0]
            f = 1
            break
        if(so[i+1][1]-so[i][1]!=D and so[i+2][1]-so[i][1]!=D):
            print(-1)
            exit()
if(f==0):
    if(so[n-1][1]-so[n-2][1]!=D):
        j = so[n-1][0]
        f = 1

if(f):
    print(j)
    exit()

print(-1)



