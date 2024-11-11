a=list(map(int,input().split(',')))
b=[]
for i in set(a):
    b.append(i)
c=[[]]
l=0
j=0
for i in b:
    if i==l+1:
        c[j].append(i)
        l+=1
    else:
        c.append([i])
        j+=1
        l=i
#print(c)
for i in range(len(c)):
    if i<len(c)-1:
        if len(c[i])>1:
            print(c[i][0],end='-')
            print(c[i][-1],end=',')
        elif len(c[i])==1:
            print(c[i][0],end=',')
    else:
        if len(c[i])>1:
            print(c[i][0],end='-')
            print(c[i][-1],end='')
        elif len(c[i])==1:
            print(c[i][0],end='')