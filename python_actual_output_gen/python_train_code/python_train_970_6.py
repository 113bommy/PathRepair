def htoM(hh,mm):
    M = hh * 60 + mm
    return M

def Mtoh(M):
    M = (M+1440)%1440
    mm = M%60
    hh = M//60

    return hh,mm

x = int(input())
hh,mm = map(int,input().split(" "))
M = htoM(hh,mm)

y = 0
while M > 0: 
    temphh,tempmm = Mtoh(M)
#    print(temphh,tempmm)
    if tempmm%10 == 7 or tempmm/10 == 7 or temphh %10 ==7 or temphh/10 == 7:
        print(y)
        break
    else:
        y += 1
        M-=x

    
