n=int(input())
t=[]
c=[]
ta=input().split()
for i in range(n):
    ta[i]=int(ta[i])
    t.append(ta[i])
t.sort()
for i in range(len(t)//2):
    if n==2:
        c.append((abs)(t[i+1]-t[i]))
    elif (sum(t))//len(t)==t[0]:
        c.append(0)
    elif i ==0 and n!=2:
        c.append (abs(t[i+1]-t[i]))
        t[i]=t[i]+c[0]
    else:
        c.append(t[(i*2)+1]-t[(i*2)])
        
print(sum(c))