fir=input()
sec=input()
a=int(sec[0:2])
b=int(fir[0:2])
c=int(sec[3:])
d=int(fir[3:])
sum=((a-b)*60+c-d)/2

b+=sum//60
d+=sum%60
if d>60:
    d-=60
    b+=1
print('%02d:%02d'%(b,d))