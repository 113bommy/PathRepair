n,k=list(map(int, input().split()))
a=list(map(int, input().split()))
if k==1:
    print("Yes")
    print(n)
if sum(a)%k==0:
    s=sum(a)//k
    i=0
    b=[0]
    t=True
    while i<n:
        while sum(a[b[-1]:i])<s and i<n:
            i+=1
        if sum(a[b[-1]:i])!=s:
            print("No")
            t=False
            break
        else:
            b.append(i)
    if t:
        print("Yes")
        c=[b[x]-b[x-1] for x in range(1,len(b))]
        print(' '.join(list(map(str, c))))
else:
    print("No")