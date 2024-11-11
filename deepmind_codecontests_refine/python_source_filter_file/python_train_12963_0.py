n = (int)(input())
F1=[0]*n
F2=[0]*n
M1=[0]*n
M2=[0]*n
m=0
f=0
for i in range(n):
    c = (input().split())
    if(c[0]=='M'):
        M1[m]=(int)(c[1])
        M2[m]=(int)(c[2])
        m=m+1
    if(c[0]=='F'):
        F1[f]=(int)(c[1])
        F2[f]=(int)(c[2])
        f=f+1
F=[0]*3232
M=[0]*3266
for i in range(f):
    for j in range(F1[i], F2[i]+1):
        F[j]=F[j]+1
for i in range(m):
    for j in range(M1[i],M2[i]+1):
        M[j]=M[j]+1
max=0
for j in range(366):
    if((F[j]>max)and(M[j]>max)):
        max=F[j]
        if(max>M[j]):
            max=M[j]
print(max*2)