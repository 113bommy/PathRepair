sticks = list(  map(int,input().split()))

sticks = sorted(sticks)
legs = -1
head,body = -1,-1
for i in range(0,3):
    if sticks[i]==sticks[i+1] and sticks[i]==sticks[i+2] and sticks[i]==sticks[i+3]:
        legs = sticks[i]
        if i==0:
            head , body = sticks[4] , sticks[5]
        elif i==2:
            head , body = sticks[0] , sticks[1]
        else:
            head , body = sticks[0] , sticks[5]
        break
if legs==-1:
    print('Alien')
else:
    if head==body:
        print('Elephent')
    else:
        print('Bear')