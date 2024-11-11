a=input()
a,b,c,d,e=[*map(int,a.split(' '))]
f=((e-c)**2 + (d-b)**2)**0.5
g=(a+f)/2
h=a-g
if(f!=0):
    if(h>=0):
        i=((b*(h+f)-(h*d))/f)
        j=((c*(h+f)-(h*e))/f)
    else:
        i=b
        j=c
        g=a
else:
        i=a/2
        j=c
print(i,j,g)
