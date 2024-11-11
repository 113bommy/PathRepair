a=int(input())
a%=360
c=min(a,360-a,(a+90)%360,abs(360-(a+90)%360),(a+180)%360,abs(360-(a+180)%360),(a+270)%360,abs(360-(a+270)%360))
if c==min(a,360-a):
    print(0)
elif c==min((a+90)%360,abs(360-(a+90)%360)):
    print(1)
elif c==min((a+180)%360,abs(360-(a+180)%360)):
    print(2)
else:
    print(3)