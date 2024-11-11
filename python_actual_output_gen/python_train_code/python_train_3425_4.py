h,m = list(map(int, input().split(':')))
t_h,t_m = list(map(int, input().split(':')))
if m >= t_m:
    m -= t_m
else:
    h = (h-1)%24
    m = m+24 - t_m
if h >= t_h:
    h -= t_h
else:
    h = (h-1)%24
print('{0:02}'.format(h)+':'+'{0:02}'.format(m))