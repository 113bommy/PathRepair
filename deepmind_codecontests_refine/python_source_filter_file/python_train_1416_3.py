h,m=map(int,input().split(":"))
if h==12: h=0
h=(h*60+m)/60
hl=h*(360//12)
ml=m*(360//60)
print(hl,ml)
