def pillar():
    temp=input().split()
    bugHeight=int(temp[0])
    appleHeight=int(temp[1])
    temp=input().split()
    dayRate=int(temp[0])
    nightRate=int(temp[1])
    if(dayRate*8+bugHeight>=appleHeight):
        return 0
    else:
        bugHeight+=dayRate*8-nightRate*12
        if(bugHeight+(dayRate*12)<appleHeight and nightRate>=dayRate):
            return -1
        if(appleHeight-(bugHeight+12*dayRate)<=0):
           return 1
        temp=((appleHeight-(bugHeight+12*dayRate))/(dayRate*12.0-12*nightRate))
        if(temp==int(temp)):
              return temp+1
        return int(temp)+2
    
print(pillar())
