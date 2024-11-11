n=int(input())
if n==1:
    print(1)
    print(1)
elif n==2:
    print(1)
    print(1)
elif n==3:
    print(2)
    print(3,1)
elif n==4:
    print(4)
    print(3,1,4,2)
elif n%4==0:
    L=[]
    for i in range(1,n//4+1):
        L.append(i*4-1)
        L.append(i*4-3)
        L.append(i*4)
        L.append(i*4-2)
    print(n)
    for e in L:
        print(e,end=' ')
elif n%4==1:
    L=[]
    for i in range(1,n//4+1):
        L.append(i*4-1)
        L.append(i*4-3)
        L.append(i*4)
        L.append(i*4-2)
    L.append(n)
    print(n)
    for e in L:
        print(e,end=' ')
elif n%4==2:
    L=[]
    for i in range(1,n//4+1):
        L.append(i*4-1)
        L.append(i*4-3)
        L.append(i*4)
        L.append(i*4-2)
    L.insert(0,n-1)
    L.append(n)
    print(n)
    for e in L:
        print(e,end=' ')
else :
    L=[]
    for i in range(1,n//4+1):
        L.append(i*4-1)
        L.append(i*4-3)
        L.append(i*4)
        L.append(i*4-2)
    L.insert(0,n-2)
    L.insert(2,n-1)
    L.append(n)
    print(n)
    for e in L:
        print(e,end=' ')