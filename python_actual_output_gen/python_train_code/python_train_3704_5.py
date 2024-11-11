r1,l1,rl=map(int,input().split())
if r1==l1:
    print(r1+l1+(rl//2)*2)
elif r1>l1:
    if rl >= abs(r1-l1) :
        print(2*r1+(rl-(abs(r1-l1)))//2)
    else:
        print((l1+rl)*2)
else:
    if rl >= abs(l1-r1):
        print(2*l1+(rl-(abs(l1-r1)))//2)
    else:
        print((r1+rl)*2)