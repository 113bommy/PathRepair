n,s1,s2,e1,e2 = list(map(int,input().split()))
s = input()
x = p = e1 - s1
y = q = e2 - s2
t = len(s)
z = 0
m1 = m2 = m3 = m4 = 0 

if(x<0):
    for i in range(t):
        if(s[i]=='W'):
            x+=1
            m1 = i+1
            if(x==0):
                break
    if(x<0):
        z = 1

if(y<0):
    for i in range(t):
        if(s[i]=='S'):
            y+=1
            m2 = i+1
            if(y==0):
                break
    if(y<0):
        z = 1

if(x>0):
    for i in range(t):
        if(s[i]=='E'):
            x-=1
            m3 = i+1
            if(x==0):
                break
    if(x>0):
        z = 1

if(y>0):
    for i in range(t):
        if(s[i]=='N'):
            y-=1
            m4 = i+1
            if(y==0):
                break
    if(y>0):
        z = 1

if(z==1):
    print("-1")
else:
    if(p<0 and q<0):
        pos = max(m1,m2)
    elif(p>0 and q>0):
        pos = max(m3,m4)
    elif(p<0 and q>0):
        pos = max(m1,m4)
    else:
        pos = max(m2,m3)
    print(pos)