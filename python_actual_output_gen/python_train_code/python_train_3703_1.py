n=int(input())
otr=0
pol=0
m=[]
for i in range(n):
    a,b=map(int,input().split())
    m.append(a)
for i in m:
    if i<0:
        otr+=1
    elif i>0:
        pol+=1
    if otr>1 and pol>1:
        print('NO')
        break
else:
    print('YES',otr,pol)