n=int(input())
j=str(input())
u=list(j)
r=0
for i in range(len(u)):
    r+=int(u[i])
if n<=r:
    print(0)
else:
    i=0
    sun=0
    u.sort()
    while sun<=abs(r-n) and i<len(u):
        sun+=9-int(u[i])
        i+=1
    print(i)
