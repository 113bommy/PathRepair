x=int(input())
if x>2:
    b=2
    if x%2==0:
        x=x//2
    else:
        x=x-1
        x=x//2
    if x%2==0:
        a=x
    else:
        a=x+1
    print(a,end=" ")
    print(b)
else:
    print(-1)