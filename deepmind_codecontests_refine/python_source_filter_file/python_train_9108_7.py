n=int(input())
to=[]
if n==1:
    print(-1)
elif n==2:
    for x in range(2):
        l,k=input().split()
        to.append(int(l))
        to.append(int(k))
    if to[0]!=to[2] and to[1]!=to[3]:
        print(abs(to[0]-to[2])*abs(to[1]-to[3]))
    else:
        print(-1)
elif n==3:
    for x in range(3):
        l,k=input().split()
        to.append(int(l))
        to.append(int(k))
    if to[0]!=to[2] and to[1]!=to[3]:
        print(abs(to[0]-to[2])*abs(to[1]-to[3]))
    elif to[0]!=to[3] and to[1]!=to[5]:
        print(abs(to[0]-to[3])*abs(to[1]-to[5]))
    else:
        print(abs(to[2]-to[4])*abs(to[3]-to[5]))
else:
    for x in range(4):
        l,k=input().split()
        to.append(int(l))
        to.append(int(k))
    if to[0]!=to[2] and to[1]!=to[3]:
        print(abs(to[0]-to[2])*abs(to[1]-to[3]))
    elif to[0]!=to[3] and to[1]!=to[5]:
        print(abs(to[0]-to[3])*abs(to[1]-to[5]))
    else:
        print(abs(to[0]-to[6])*abs(to[1]-to[7]))