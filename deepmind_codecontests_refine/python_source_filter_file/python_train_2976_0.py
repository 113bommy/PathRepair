# eps = 10**-6

#def s():
#n, power = (int(x) for x in input().split())
n__power = input().split()
n = int(n__power[0])
power = int(n__power[1])

items = []
for _ in range(n):
    p__a = input().split()
    p = int(p__a[0])
    a = int(p__a[1])
    time = a/p
    items.append( (time, p, a))
items.sort()
sys_power = -power
sys_amount = 0
sys_time = None
while len(items) > 0:
    t, p, a = items.pop(0)
    if sys_time is not None and sys_time < t:
        break
    sys_power += p
    sys_amount += a
    if sys_power > 0:
        sys_time = sys_amount / sys_power
if sys_time is None: print( '-1')
print( sys_time)
    
    
#print(s())