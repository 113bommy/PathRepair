N=int(input())
k=2
while N>=(k-1)*k/2:
    if N==(k-1)*k/2:
        print("Yes")
        print(k)
        a=list([] for i in range(k))
        t=1
        for i in range(0,k):
            for n in range(1,k-i):
                a[i].append(t)
                a[i+n].append(t)
                t+=1
        for i in range(k):
            print(str(k-1)+" "+" ".join(map(str,a[i])))
        exit()
    else:
        k+=1
print("No")
