import math
d,h,v,e = map(int,input().split())

if e > v:
	exit(print('NO'))
ans = h / (v/(math.pi * (d/2)**2) - e)
print('NO' if ans < 0 else 'YES\n'+str(ans))
