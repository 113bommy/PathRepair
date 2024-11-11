vp = int(input())
vd = int(input())
t = int(input())
f = int(input())
c = int(input())

p = 0
b = 0
if vp > vd:
    while p < c:

        time_adv = t
        time_catch = (p + time_adv * vp) / (vd - vp)
        
        p += (time_adv + time_catch) * vp
        t = p / vd + f
        b += 1
    b -= 1

print(b)
