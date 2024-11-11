import fileinput;

str = input();
sstr = str.split(' ')
a,b,w,x,c = int(sstr[0]),int(sstr[1]),int(sstr[2]),int(sstr[3]),int(sstr[4])

dif = c-a

up = max(0,int((dif*x-b)/(w-x)))
b = b+up*(w-x)

count = up
while dif > 0:
    if (b >= x):
        factor = min(int((b - x)/x)+1,dif)
        dif = dif-factor
        b = b - x*factor
    else:
        factor = int( (x-b-1)/(w-x) )+1
        b = factor*(w-x)+b
        count = count+factor

print(count+(c-a))
