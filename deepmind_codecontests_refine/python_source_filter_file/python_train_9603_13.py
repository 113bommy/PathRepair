def fun(a,b,c,d):
    if a<=b:
        print(a)
        return
    if d>=c:
        print(-1)
        return
    
    val=(a-b)//(c-d)
    if b+(c-d)*val>=a:
        print(b+val*c)
    else:
        print(b+(val+1)*c)





for i in range(0,int(input())):
    a,b,c,d=[int(x) for x in input().split()]
    fun(a,b,c,d)
