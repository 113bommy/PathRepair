import math
a = int(input())
t=[]
tt=[]
for x in range(0,a):
    t.append(0)
    tt.append(0)
    
for x in range(0,a):
    h=input()
    for y in range(0,a):
        if h[y]=="C":
            t[x]+=1
            tt[y]+=1

j =0
for x in range(0,a):
    if t[x]>=2 : j+= math.factorial(t[x])/(math.factorial(2)*math.factorial(t[x]-2))
    if tt[x]>=2 :j+= math.factorial(tt[x])/(math.factorial(2)*math.factorial(t[x]-2))
print(int(j))
