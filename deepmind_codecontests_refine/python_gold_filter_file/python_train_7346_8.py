n=int(input())
if n==1:
    print(1)
    print(1)
elif n==2:
    print(1)
    print(2)
else:
    t=[]
    i=1
    while i<=n:
        n-=i
        t.append(i)
        i+=1
    k=len(t)
    t[k-1]+=n
    print(k)
    for i in t:
        print(i,end=" ")