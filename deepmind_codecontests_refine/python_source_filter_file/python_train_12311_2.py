t =int(input())
while(t>0):
    a,b,c =[int(i) for i in input().split()]
    a1,a2 =-1,-1
    if a<c:
        a1 = 1
        if b*a<c:
            a2=b
        print(a1,a2)
    else:
        print(-1,b)    
    t-=1