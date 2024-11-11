import sys
s=input()
A,B =map(int,input().split())
t = 0
k=0
L=len(s)
table=[[] for i in range(2)]
for i in range(len(s)):
    if s[i]=='F':
        k+=1
    else:
        table[t].append(k)
        t=(t+1)%2
        k=0
table[t].append(k)
Lx=set()
Lx.add(table[0][0])
for i in range(1,len(table[0])):
    x=table[0][i]
    T=set()
    for a in Lx:
        if -L<=a+x<=L:
            T.add(a+x)
        if -L<=a-x<=L:
            T.add(a-x) 
    Lx=T
flag=True
for a in Lx:
    if a==A:
        flag =False
if flag:
    print('No')
    sys.exit()

Lx=set()
Lx.add(0)
for i in range(len(table[1])):
    x=table[1][i]
    T=set()
    for a in Lx:
        if -L<=a+x<=L:
            T.add(a+x)
        if -L<=a-x<=L:
            T.add(a-x) 
    Lx=T
flag=True
for a in Lx:
    if a==B:
        flag =False
if flag:
    print('No')
    sys.exit()
print('Yes')