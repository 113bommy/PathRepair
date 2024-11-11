mas = list(map(int, input().split()))
w = mas[0]
h = mas[1]
alf = mas[2]
import math
sina = abs(math.sin(alf/180*math.pi))
cosa = abs(math.cos(alf/180*math.pi))
sinb = h / ((w ** 2 + h ** 2) ** 0.5)
cosb = w / ((w ** 2 + h ** 2) ** 0.5)
sin2b = 2 * sinb * cosb
#print(w,h,alf)
if (sin2b >= sina):
    #print(sina, cosa)
    diskr = (cosa + 1) ** 2 - sina ** 2
    disc = w * (cosa + 1) - h * (sina)
    disf = h * (cosa + 1) - w * (sina)
    c = disc / diskr
    f = disf / diskr
    res = w * h - (c ** 2 + f ** 2) * sina * cosa
elif(alf == 90):
    res = min(w, h) ** 2
else:
    res = min((h ** 2) / sina, (w ** 2) / sina)
print(res)