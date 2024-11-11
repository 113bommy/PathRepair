r=input()
c,n,e,t,u=0,1,0,0,0
for i in r:
    if i=="n":
        n+=1
    if i=="e":
        e+=1
    if i=="t":
        t+=1
    if i=="i":
        u+=1
    if n>=2 and e>=3 and t>=1 and u>=1:
        c+=1
        n,e,t,u=n-3,e-3,t-1,u-1
print(c)