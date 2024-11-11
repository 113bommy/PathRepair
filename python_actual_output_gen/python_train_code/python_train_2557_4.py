for _ in [0]*int(input()):
    l=list(map(int,input().split()))
    l.sort()
    a,b=l
    if 2*b-a>0 and (2*b-a)%3==0 and 2*a-b>0 and (2*a-b)%3==0:
        print("YES")
    else:
        print("NO")





