t=int(input())
for you in range(t):
    n=int(input())
    l=input().split()
    li=[int(i) for i in l]
    if(n==1):
        print(1)
        print(1,1,0)
        continue
    z=sum(li)
    ok=z
    if(z%n):
        print(-1)
        continue
    print(3*n-1)
    print(1,2,li[0])
    li[1]+=li[0]
    print(2,1,li[1]//2)
    li[0]=2*(li[1]//2)
    li[1]=li[1]%2
    for i in range(n-1):
        z=li[i+1]%(i+2)
        if(z==0):
            print(1,i+2,0)
        else:
            print(1,i+2,(i+2)-z)
            li[i+1]+=(i+2-z)
            li[0]-=(i+2-z)
        print(i+2,1,(li[i+1])//(i+2))
    for i in range(n-1):
        print(1,i+2,ok//n)