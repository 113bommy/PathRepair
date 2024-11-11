a,b,c,d=map(int,input().split())
r=[['A' for i in range(50)] for j in range(50)]
flag=0
print(50,50)
for i in range(0,8,2):
    for j in range(0,50,2):
        r[i][j]='D'
        d-=1
        if(d==0):
            flag=1
            break
    if(flag==1):
        break
flag=0
for i in range(8,16,2):
    for j in range(0,50,2):
        r[i][j]='C'
        c-=1
        if(c==0):
            flag=1
            break
    if(flag==1):
        break
for i in range(49,32,-1):
    for j in range(50):
        r[i][j]='B'
a-=1
b-=1
flag=0
if(a!=0):
    for i in range(34,50,2):
        for j in range(0,50,2):
            r[i][j]='A'
            a-=1
            if(a==0):
                flag=1
                break
        if(flag==1):
            break
flag=0
if(b!=0):
    for i in range(16,50):
        for j in range(0,50,2):
            r[i][j]='B'
            b-=1
            if(b==0):
                flag=1
                break
        if(flag==1):
            break
for i in r:
    for j in i:
        print(j,end="")
    print()

