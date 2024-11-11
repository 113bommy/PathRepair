import sys
s=input()
A,B =map(int,input().split())
table=[[] for i in range(2)]#0が横1が縦
t = 0
k=0
for i in range(len(s)):
    if s[i]=='F':
        k+=1
    else:
        table[t].append(k)
        t=(t+1)%2
        k=0
table[t].append(k)
L=len(s)
Lx=[set() for i in range(len(table[0]) +1)]
Ly=[set() for i in range(len(table[1]) +1)]
Lx[0].add(0)
Ly[0].add(0)
for i in range(len(table[0])):
    x = table[0][i]
    if i==0:
        Lx[1].add(x)
        continue
    for a in Lx[i]:
        if -L<=a+x<=L:
            Lx[i+1].add(a+x)
        if -L<=a-x<=L:
            Lx[i+1].add(a-x) 
flag=True
for a in Lx[len(table[0])]:
    if a==A:
        flag =False
if flag:
    print('No')
    sys.exit()
    
for i in range(len(table[1])):
    x = table[1][i]
    for a in Ly[i]:
        if -L<=a+x<=L:
            Ly[i+1].add(a+x)
        if -L<=a-x<=L:
            Ly[i+1].add(a-x)
flag=True
for a in Ly[len(table[1])]:
    if a==B:
        flag =False
if flag:
    print('No')
    sys.exit()
    
print('Yes')
