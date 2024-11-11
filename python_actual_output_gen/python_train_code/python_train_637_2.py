tc=int(input())
while tc!=0:
    tc=tc-1
    n,k=map(int,input().split(' '))
    a=[]
    if n%2==0:
        if k%2==0:
            for i in range(0,k-1):
                a.append(1)
            if n-(k-1)<0:
                print("NO")
                continue
            a.append(n-(k-1))
        else:
            for i in range(0,k-1):
                a.append(2)
            if n-2*(k-1)<0:
                print("NO")
                continue
            a.append(n-2*(k-1))
    else:
        if k%2==0:
            print("NO")
            continue
        else:
            for i in range(0,k-1):
                a.append(1)
            if n-(k-1)<0:
                print("NO")
                continue
            a.append(n-(k-1))
    print("YES")
    for i in a:
        print(i,end=' ')
    print()
    