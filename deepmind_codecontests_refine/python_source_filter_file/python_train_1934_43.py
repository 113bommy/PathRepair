x = int(input())
i=0
j=0
if x%2==0:
    y=x/2
    print(int(y))
    while j<y:
        print(2,end=" ")
        j+=1
else :
    y = x / 2
    print(int(y+1))
    y-=2

    while j <y:
        print(2,end=" ")
        j+=1
    print(3)