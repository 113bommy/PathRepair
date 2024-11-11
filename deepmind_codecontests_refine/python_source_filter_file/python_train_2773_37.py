import math 
x=int(input())
h,m=[int(i) for i in input().split()]
cnt=0
while(1):
    if(h%10==7 or m%10==7):
        break
    if(m-x<0):
        h=h-math.ceil(abs(m-x)/60)
        if(h<0):
            h=24+h
        m=60+(m-x)
    else:
        m=m-x
    print(h,":",m)
    cnt+=1
print(cnt)