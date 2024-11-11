while True:
    a=input()
    if(a!="start"):
        break
    d=1
    low=0
    high=0
    print("? 0 1")
    o=input()
    if(o=='x'):
        print("! 1")
        continue
    while(1):
        print("?",d,2*d)
        o=input()
        if(o=='x'):
            low=d+1
            high=2*d
            break
        else:
            d=d*2
    while(low<high):
        m=(low+high)/2
        print("?",m,high)
        o=input()
        if(o=='x'):
            low=m+1
        else:
            high=m
    print("!",high)
    
