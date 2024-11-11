x, y, z ,t1, t2, t3 = [int(a) for a in input().split(" ")]

time_stairs = abs(x-y)*t1

time_elevator = abs(z-x)*t2 + 2*t3 + t2*abs(x-y)

if time_elevator > time_stairs:
    print("NO")
else:
    print("YES")