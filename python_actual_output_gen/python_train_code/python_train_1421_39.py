misha,vaysa,m,v = map(int,input().split())
def formula(points,time):
    return max((3*points),(points-(points/250)*time))

first = formula(misha,m)
second = formula(vaysa,v)
if first > second:
    print('Misha')
elif second > first:
    print("Vasya")
else:
    print("Tie")