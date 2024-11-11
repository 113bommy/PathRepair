ch=input()
t=[]
m=[]
n=[]
k=0
ch1=''
i=0
a=(len(ch)//4)*4
while i<(a):
    ch1=ch[i:i+4]
    t.append(ch1)
    i=i+4
    ch1=''
ch2=ch[a:len(ch)]
i=0
for i in range(4-len(ch2)):
    ch2=ch2+'*'
t.append(ch2)
i=0
for j in range(4):
    i=0
    while (t[i][j] in ['!','*']) and (i<(len(t)-1)):
        i=i+1
    if (not(t[i][j] in ['!','*'])) :
        m.append(t[i][j])
    else:
        m.append('!')
    s=0
    ch2=0
    for k in range(len(t)):
        if t[k][j]=='!':
            s=s+1
        ch2=m[j]+str(s)
    n.append(ch2)
n.sort()
b=n[0]
c=n[1]
d=n[2]
e=n[3]
n[0]=d
n[1]=b
n[2]=e
n[3]=c
ch3=''
for i in range(4):
    ch3=ch3+n[i][1]+' '
print(ch3[:(len(ch3)-1)])