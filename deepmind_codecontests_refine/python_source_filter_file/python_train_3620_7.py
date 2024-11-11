import sys
input=sys.stdin.readline

N=int(input())

X1={}
X2={}

X={}
Y={}

for i in range(N):
    x,y,u=input().split()
    x=int(x)
    y=int(y)
    if x+y not in X1:
        X1[x+y]=[[x,u]]
    else:
        X1[x+y].append([x,u])
    if y-x not in X2:
        X2[y-x]=[[x,u]]
    else:
        X2[y-x].append([x,u])
    if x not in X:
        X[x]=[[y,u]]
    else:
        X[x].append([y,u])
    if y not in Y:
        Y[y]=[[x,u]]
    else:
        Y[y].append([x,u])


Dead=10**9


for k,v in X1.items():
    D=-1
    R=-1
    v.sort()
    #print(v)
    for a,u in v:
        if u=="D":
            D=a
        elif u=="R":
            R=a
        elif u=="L":
            if D>=0:
                Dead=min(Dead,(a-D)*10)
        elif u=="U":
            if R>=0:
                Dead=min(Dead,(a-R)*10)
for k,v in X2.items():
    U=-1
    R=-1
    v.sort()
    #print(v)
    for a,u in v:
        if u=="U":
            U=a
        elif u=="R":
            R=a
        elif u=="L":
            if U>=0:
                Dead=min(Dead,(a-U)*10)
        elif u=="D":
            if L>=0:
                Dead=min(Dead,(a-R)*10)
for k,v in X.items():
    U=-1
    v.sort()
    #print(v)
    for a,u in v:
        if u=="U":
            U=a
        elif u=="D":
            if U>=0:
                Dead=min(Dead,(a-U)*5)
for k,v in Y.items():
    R=-1
    v.sort()
    #print(v)
    for a,u in v:
        if u=="R":
            R=a
        elif u=="L":
            if R>=0:
                Dead=min(Dead,(a-R)*5)
if Dead==10**9:
    print("SAFE")
else:
    print(Dead)