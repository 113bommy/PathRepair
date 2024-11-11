dhve = list(map(int, input().split()))
d, h, v, e = dhve[0], dhve[1], dhve[2], dhve[3]
pi = 3.14159265358979

V = (v*4)/(d*d*pi)
relative_speed = V-e
if relative_speed <= 0:
    print("NO")
else:
    print("YES")
    print(h/relative_speed)
