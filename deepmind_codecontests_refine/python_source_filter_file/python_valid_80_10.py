
testcases=int(input())
while testcases:
    d=int(input())
    num=input()
    if "0" in num:
        index=num.find("0")
        if index+1<=d//2:
            l1=index
            r1=d-1
            l2=l1+1
            r2=d-1
        else:
            l1=0
            l2=0
            r1=index
            r2=r1-1
    else:
        l1=0
        r1=d-1
        l2=l1+1
        r2=d-1
    print(l1+1,r1+1,l2+1,r2+1)
    testcases-=1