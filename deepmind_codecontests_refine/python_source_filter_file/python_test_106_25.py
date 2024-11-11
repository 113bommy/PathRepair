t=int(input())
while(t):
    n=int(input())
    a=[]
    for i in range(1,n+1):
        a.append(i)
    print(*a)
    t-=1