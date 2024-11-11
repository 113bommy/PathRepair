t=1
for q in range(t):
    n=int(input())
    ch=input()
    L=[int(i)for i in ch.split()]
    L2=[n]
    L3=[L[0]]
    for i in range(1,n):
        L3.append(L[i]-L[i-1])
    
    

    for k in range(1,n):
        test=True
        for i in range(n-k):
            if L3[i]!=L3[i+k]:
                test=False
        if test:
            L2.append(k)
    L2.sort()
    print(len(L2))
    s=""
    for i in L2:
        s+=str(i)+" "
    print(s)
    
        
