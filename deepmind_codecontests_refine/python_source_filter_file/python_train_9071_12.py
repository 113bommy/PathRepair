import math

def getValue(power):
    if power%2==0:
        return 1+2*((pow(4,power//2))//3)
    else:
        return 2+2*((2*(pow(4,power//2)-1))//3)

mod=1000000007

x=input().split(' ')

l=int(x[0])
r=int(x[1])


lp=int(math.ceil(math.log(l,2)))
lower=pow(2,lp)
lowerVal=getValue(lp)
le=lp==int(math.floor(math.log(l,2)))

up=int(math.floor(math.log(r,2)))
upper=pow(2,up)
upperVal=getValue(up)
ue=up==int(math.ceil(math.log(r,2)))


lVal=getValue(lp-1)
rVal=getValue(up+1)

if lowerVal%2==0:
    startEven=lowerVal
    if le:
        startOdd=getValue(lp+1)
    else:
        startOdd=lVal+2*(l-pow(2,lp-1))
else:
    startOdd=lowerVal
    if le:
        startEven=getValue(lp+1)
    else:
        startEven=lVal+2*(l-pow(2,lp-1))

if upperVal%2==0:
    endEven=upperVal+2*(r-upper)
    endOdd=getValue(up-1) + 2*((pow(2,up-1))-1)
else:
    endOdd=upperVal+2*(r-upper)
    endEven=getValue(up-1) + 2*((pow(2,up-1))-1)

#print(startOdd)
#print(endOdd)
#print(startEven)
#print(endEven)
sm=0
p=(endOdd-startOdd)//2+1
sm=(sm+(p*(startOdd+p-1))%mod)%mod

p=(endEven-startEven)//2+1
sm=(sm+(p*(startEven+p-1))%mod)%mod

print(sm)
        




