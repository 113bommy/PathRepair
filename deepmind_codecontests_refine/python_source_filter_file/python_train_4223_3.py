s = input()
l = s.split(" ")

d = int(l[0])
k = int(l[1])
a = int(l[2])
b = int(l[3])
t = int(l[4])
if (d <= k ):
    print (d*a)
else:
    car = k * a + t
    foot = k * b
    if (foot <= car):
        print (k * a + ( d - k ) * b)
    else:
        tcar = int(d / k) * car
        dist = d % k
        c1 = tcar + dist * a
        c2 = tcar - t + dist * b
        if (dist == 0):
            c1 -= t
        if (c1 <= 1):
            print (c1)
        else:
            print (c2)