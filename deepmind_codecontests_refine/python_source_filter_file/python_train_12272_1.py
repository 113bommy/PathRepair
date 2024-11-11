n=int(input())
t=[[int(num)for num in input().split(':')]for i in range(n)]
for i in range(n):
    h=t[i][0]
    m=t[i][1]
    an_s=h*30+m/120
    an_l=m*6
    dif=0
    if abs(an_s-an_l)<180:dif=abs(an_s-an_l)
    else:dif=360-abs(an_s-an_l)
    if dif<30:
        print("alert")
    elif dif<90:
        print("warning")
    else:
        print("safe")