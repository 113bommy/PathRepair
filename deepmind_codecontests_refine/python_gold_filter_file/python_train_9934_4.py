t1=input().split(':')
t2=input().split(':')
x1=int(t1[0])
x2=int(t1[1])
x3=int(t2[0])
x4=int(t2[1])
#x1:x2
#x3:x4
if x1>=x3 and x2>=x4:
    mins=str(x1-x3)
    hours=str(x2-x4)
    if len(mins)==1:
        mins='0'+mins
    if len(hours)==1:
        hours='0'+hours
    print(mins+':'+hours)
elif x1<=x3 and x2<x4:
    mins=str(x1+23-x3)
    hours=str((x2-x4+60)%60)
    if len(mins)==1:
        mins='0'+mins
    if len(hours)==1:
        hours='0'+hours
    print(mins+':'+hours)
elif x1<=x3 and x2>=x4:
    mins=str(x1+24-x3)
    hours=str((x2-x4)%60)
    if len(mins)==1:
        mins='0'+mins
    if len(hours)==1:
        hours='0'+hours
    print(mins+':'+hours)
else:
    mins=str(x1-x3-1)
    hours=str((x2-x4+60)%60)
    if len(mins)==1:
        mins='0'+mins
    if len(hours)==1:
        hours='0'+hours
    print(mins+':'+hours)
