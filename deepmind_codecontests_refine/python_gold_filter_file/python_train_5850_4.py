for itr in range(int(input())):
    n=input().split()
    c=int(n[0])
    m=int(n[1])
    x=int(n[2])
    count=0
    if c<m:c,m=m,c
    if m<=x: 
        print(m)
    else: 
        if c-x>=2*(m-x):print(x+m-x)
        else: print(x+(c+m-2*x)//3)