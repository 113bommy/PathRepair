import math
d,h,v,e = map(int, input().split())
initial_vol = math.pi * ((d/2)**2) * h
rain_per_second = math.pi * ((d/2) ** 2) * e
#print(initial_vol, rain_per_second)

if(v <= rain_per_second):
    print("NO")
else:
    print("YES")
    print(round(initial_vol / (v  - rain_per_second), 12))