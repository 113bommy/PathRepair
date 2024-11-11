l=input().split()
n,m=int(l[0]),int(l[1])
d=[]
for i in range(n):
    ch=input()
    d.append(ch)
l=input().split()
l=[(int(x)-1) for x in l]
p=len(d[l[0]])
B=True
D=[]

for i in l:
    if len(d[i])==p:
        D.append(d[i])
    else:
        B=False
        break
t=[]

if B:
    for i in D[0]:
        t.append(i)
    
    for i in range(len(D)):
        for j in range(len(D[i])):
            if D[i][j]!=t[j] and t[j]!="?":
                t[j]='?'

if B==False:
    print('No')
else:
    C=True
    for i in range(len(d)):
        if i not in l:
            C=True
        if i not in l and len(d[i])==p:
            for j in range(len(d[i])):
                if t[j]!="?" and d[i][j]!=t[j]:
                    C=False
        elif i not in l and len(d[i])!=p:
            C=False
        
        if C==True and i not in l:
            break
    if C==False:
        print("Yes")
        for i in t:
            print(i,end="")
    else:
        print('No')
    
