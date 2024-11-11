n=int(input())
l=[]
for i in range(n):
    l.append(list(map(str,input().split())))
s=0
for i in range(n):
    if(int(l[i][1])>=2400):
        if(int(l[i][2])>int(l[i][1])):
            s=1
            break
if(s==1):
    print('YES')
else:
    print('NO')
