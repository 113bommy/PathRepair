for t in range(int(input())):
    
    x = list(map(int, input().split()))
    
    s=input()
    n0=0
    n1=0
    
    
    for i in s:
        if(i=='0'):
            n0=n0+1
        else:
            n1=n1+1
    tot=(n0*x[1])+(n1*x[2])    
    if(x[3]+x[1]<x[2]):
            tot=n0*x[1]+n1*(x[2]+x[1])
    if(x[3]+x[2]<x[1]):
        tot=n0*(x[3]+x[2])+n1*x[2]
    print(tot)
