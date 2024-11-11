for _ in range(int(input())):
    a,b,c,d = map(int,input().split())
    if(b>=a):
        print(b)
    elif(d>=c):
        print(-1)
    else:
        l = 1
        r = 10**9
        while(l!=r):
            mid = (l+r)//2
            if(b + ((c-d)*mid) >= a):
                r = mid
            else:
                l = mid + 1
        print(b+(l*c))
