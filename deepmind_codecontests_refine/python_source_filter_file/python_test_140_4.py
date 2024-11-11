t=int(input())
for i in range(t):
    n=int(input())
    c2=0
    c3=0
    c6=0
    for j in range(1,int(n**(0.5))+1):
        if j**2<=n:
            c2+=1
    for j in range(1,int(n**(1/3))+2):
        if j**3<=n:
            c3+=1
    for j in range(1,int(n**(1/6))+1):
        if j**6<=n:
            c6+=1
    print(c2+c3-c6)