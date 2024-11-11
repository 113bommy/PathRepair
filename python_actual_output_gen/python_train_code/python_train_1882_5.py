t=int(input())
for i in range(t):
    n=int(input())
    
    r=str(n)
    l=len(r)
    # print(r)
    # l=len(n)
    m=[]
    for ind,ele in enumerate(r):
        if(ele!=0):
            m.append(ele+('0'*(l-ind-1)))

    print(len(m))
    print(*m)