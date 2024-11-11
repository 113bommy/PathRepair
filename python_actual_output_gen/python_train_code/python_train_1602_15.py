t = int(input())
ttt=t
tt=0
if t>31:
    t=t-32
    tt=tt+32
if t>15:
    t=t-16
    tt=tt+4
if t>7:
    t=t-8
    tt=tt+1
if t>3:
    t=t-4
    tt=tt+8
if t>1:
    t=t-2
    tt=tt+2
if t>0:
    t=t-1
    tt=tt+16
print(tt)
    
        
