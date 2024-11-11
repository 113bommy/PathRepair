t=int(input())
for _ in range(0,t):
    n,x,y=map(int,input().strip().split(" "))
    j=n-1
    while(j>0):
        if((y-x)%j==0):
            d=int((y-x)/j)
            break
        j-=1
    i=x
    s=[]
    while(i<y+1 and n>0):
        s.append(i)
        i+=d
        n-=1
    i=x-d
    while(i>0 and n>0):
        s.append(i)
        i-=d
        n-=1
    i=y+d
    while(n>0):
        s.append(i)
        i+=d
        n-=1
    s.sort()
    print(*s)