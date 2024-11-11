t=int(input())
r=[]
py=[]
for i in range(t):
    x,y=map(int , input().strip().split(' '))
    r.append([x,y])
    py.append(y)
r.sort()
py.sort()

c=0
c1=1
c2=1
c3=1
for i in range(t-1):
    if py[i]==py[i+1]:
        c3+=1
        if i==t-2:
            c+=((c3)*(c3-1))//2
    else:
        c+=((c3)*(c3-1))//2
        c3=1
        
    if r[i][0]==r[i+1][0] and r[i][1]==r[i+1][1]:
        c2+=1
        if i==t-2:
            c+=((c2)*(c2-1))//2
    else:
        c-=((c2)*(c2-1))//2
        c2=1
        
    if r[i][0]==r[i+1][0]:
        c1+=1
        if i==t-2:
            c+=((c1)*(c1-1))//2
    else:
        c+=((c1)*(c1-1))//2
        c1=1
        
print(c)

        