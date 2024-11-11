def checker(x,n):
    c=0
    if abs(x)%2==0:
        d=-1
    else:
        d=1
    if n%4==1:
        c=x+d*(1+4*(n//4))
    elif n%4==2:
        c=x+d
    elif n%4==3:
        c=x-d*(4*(1+n//4))
    elif n%4==0:
        c=x

    return c
testcase=int(input())
for i in range(0,testcase):
    x,n=map(int,input().split())
    print(checker(x,n))
