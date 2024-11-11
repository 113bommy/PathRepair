R = lambda : map(int, input().split())
a, ta = R()
b, tb = R()

h, m = map(int, input().split(':'))

initial_time = 5*60
final_time = 23*60 + 59
bus_itime = h*60 +m
bus_ftime = bus_itime + ta
c = 0
for i in range(initial_time, final_time+1, b):
    if (i >= bus_itime and i < bus_ftime):
        c += 1
        #print(i)
    elif (i + tb > bus_itime and i + tb < bus_ftime):
        c += 1
        #print(i, i + tb, bus_itime, bus_ftime)
    if (i >= bus_ftime):break
    #print(i, i + tb, bus_itime, bus_ftime, "------")
print(c)
