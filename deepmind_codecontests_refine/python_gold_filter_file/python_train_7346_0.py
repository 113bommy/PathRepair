n = int(input())
if(n<=2):
    print(1)
    print(n)
else:
    l = []
    total = 0
    for i in range(1,n):
        total+=i
        if total>=n:
            l.append(i)
            break
        else:
            l.append(i)
    #print(l)
    if total>n:
        l.remove(total-n)
    print(len(l))
    for i in l:
        print(i,end=' ')