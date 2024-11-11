t=input()
t=int(t)
for i in range(t):
    n,k=input().split(" ")
    n=int(n)
    k=int(k)
    print(k)
    arr=list(map(int,input().rstrip().split()))
    d=max(arr)
   
    c=[]
    cc=[]
    for j in range(len(arr)):
        c.append(d-arr[j])


   
    dd=max(c)

    for k1 in range(len(c)):
        cc.append(dd-c[k1])
    if k%2==0:
        print(*cc)
    else:
        print(*c)
       