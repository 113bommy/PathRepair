from sys import stdout, stdin
for i in stdin:
    q=int(i)
    break
for i in stdin:
    i=list(map(int,i.strip()))
    A=[]
    E=[j for j in i if j%2==0]
    O=[j for j in i if j%2==1]
    a,b=0,0
    while a+b!=len(i)-2:
        if a==len(E):
            A.append(O[b])
            b+=1
        elif b==len(O):
            A.append(E[a])
            a+=1
        elif E[a]<O[b]:
            A.append(E[a])
            a+=1
        else:
            A.append(O[b])
            b+=1
        
    A=list(map(str,A))
    stdout.write(''.join(A)+'\n')
    q-=1
    if not q:
        break